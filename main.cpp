#include "graphics.hpp"
#include "widgets.hpp"
#include "app.hpp"
#include "push_button.hpp"
#include "static_pics.hpp"
#include "map.hpp"
#include "spinbox.hpp"
#include "jatekmester.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace genv;
using namespace std;

class App;
//class JatekMester;

struct My_App : public App
{
protected:
    JatekMester master;
    Push_button* start;
    Push_button* exit;
    Static_pics* cim;
    Funktor_Button* easy;
    Funktor_Button* medium;
    Funktor_Button* hard;
    Push_button* _back;
    Funktor_Button* back2;
    Field* palya;
    Spinbox* box;
    Static_pics* moldva;

public:
    vector<Spinbox*> boxes;

     My_App(int w_width, int w_height) : App(w_width, w_height)
    {
        // Start menü
        cim = new Static_pics(this, 150, 100, 500, 200, "cim", "kepek/cim.csv");
        start = new Push_button(this, 300, 280, 200, 50, "play", "kepek/Play_icon.csv", "kepek/playkj.csv");
        exit = new Push_button(this, 300, 360, 200, 50, "exit", "kepek/exit.csv", "kepek/exitkj.csv");

        // Szintek
        _back = new Push_button(this, 300, 520, 200, 50, "back", "kepek/back.csv", "kepek/backkj.csv");
        easy = new Funktor_Button(this, 300, 280, 200, 50, "easy", "kepek/easy.csv", "kepek/easykj.csv", [&]() { level("easy.txt"); });
        medium = new Funktor_Button(this, 300, 360, 200, 50, "medium", "kepek/medium.csv", "kepek/mediumkj.csv", [&]() { level("medium.txt"); });
        hard = new Funktor_Button(this, 300, 440, 200, 50, "hard", "kepek/hard.csv", "kepek/hardkj.csv", [&]() { level("hard.txt"); });

        // Pálya
        palya = new Field(this, 125, 200, 550, 550, "palya");
        back2 = new Funktor_Button(this, 100, 100, 200, 50, "back2", "kepek/back.csv", "kepek/backkj.csv", [&]() { board_clear(); });
        moldva = new Static_pics(this, 400, 100, 200, 50, "+oldva", "kepek/megoldva.csv");
    }

    void level(std::string file)
    {
        event ev;
        vector<string> w;
        string line;
        ifstream load(file);
        for (int i = 0; i < 10000; i++)
        {
            getline(load, line);
            w.push_back(line);
        }
        line = w[rand()%10000];
        int x = 0;
        string c;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int                 szam = stoi(string(1, line[x]));
                master._board.push_back(szam);
                c = to_string(master._board[x]);
                box = new Spinbox(this, 125 + j * 60 + j * 1, 200 + i * 60 + i * 1, 60, 60, "box", 1, 9, c, [&]() { Board_set(boxes); });
                boxes.push_back(box);
                x++;
            }
        }
    }

    void Board_set(vector<Spinbox*> s)
    {
        for (int i = 0; i < 81; i++)
        {
            master._board[i] = s[i]->_i;
        }
        int jo = 0;
        for (int i = 0; i < 81; i++)
        {
            s[i]->szin = master.isMoveValid(master.GetRow(i), master.GetCol(i), s[i]->_i, i);
            if (s[i]->szin && s[i]->_i > 0)
                jo++;
        }

        if (jo == 81)
        {
            megoldva = true;
        }
        else megoldva = false;
    }

    void board_clear()
    {
        cout << "Delet" << endl;

        std::vector<Widget*> updatedWidgets;

        for (Widget* widget : widgets)
        {
            if (dynamic_cast<Spinbox*>(widget) == nullptr)
            {
                updatedWidgets.push_back(widget);
            }
        }

        widgets = updatedWidgets;

        for (Spinbox* box : boxes)
        {
            delete box;
        }

        master._board.clear();
        boxes.clear();
    }
};

int main()
{
    My_App* game = new My_App(800, 800);
    game->App_loop();
    return 0;
}

