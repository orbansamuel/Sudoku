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
class JatekMester;

struct Menu : public App
{
protected:
    Push_button * start;
    Push_button * exit;
    Static_pics * cim;
    Funktor_Button * easy;
    Funktor_Button * medium;
    Funktor_Button * hard;
    Push_button * _back;
    Field * palya;
    Spinbox * box;
    vector<Spinbox*> boxes;


public:
    Menu(int w_width, int w_height) : App(w_width, w_height)
    {
        //start menü -
        cim = new Static_pics(this,150,100,500,200,"cim","kepek/cim.csv");
        start = new Push_button(this,300,280,200,50,"play","kepek/Play_icon.csv","kepek/playkj.csv");
        exit = new Push_button(this,300,360,200,50,"exit","kepek/exit.csv","kepek/exitkj.csv");

        //Szintek
        _back = new Push_button(this,300,520,200,50,"back","kepek/back.csv","kepek/backkj.csv");
        easy = new Funktor_Button(this,300,280,200,50,"easy","kepek/easy.csv","kepek/easykj.csv",[&](){level("easy.txt");});
        medium = new Funktor_Button(this,300,360,200,50,"medium","kepek/medium.csv","kepek/mediumkj.csv",[&](){level("medium.txt");});
        hard = new Funktor_Button(this,300,440,200,50,"hard","kepek/hard.csv","kepek/hardkj.csv",[&](){level("hard.txt");});

        //pálya

        palya = new Field(this,125,200,550,550,"palya");


    }

    void level(std::string file)
    {
        vector<string> w;
        string line;
        ifstream load (file);
        for(int i = 0; i < 10000;i++)
        {
            getline(load,line);
            w.push_back(line);
        }
        line = w[rand()%10000];
        int x = 0;
        int k = 0;
        string c;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
        {
            {
                c = line[x];
                box = new Spinbox(this,125+j*60+j*1,200+i*60+i*1,60,60,"box",1,9,c);
                boxes.push_back(box);
                x++;
            }
        }
    }

    void Board_set()
    {
        for(int i = 0; i < boxes.size();i++)
        {


        }

    }

};



int main()
{
    Menu * menu = new Menu(800,800);
    menu->menu_loop();
    return 0;

}
