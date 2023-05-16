#include "graphics.hpp"
#include "widgets.hpp"
#include "app.hpp"
#include "push_button.hpp"
#include <iostream>
#include "static_pics.hpp"
#include "map.hpp"
#include "spinbox.hpp"
#include <fstream>
#include <string>
#include <sstream>

using namespace genv;
using namespace std;

class App;

struct Menu : public App
{
protected:
    Push_button * start;
    Push_button * exit;
    Static_pics * cim;
    Push_button * easy;
    Push_button * medium;
    Push_button * hard;
    Push_button * _back;
    Field * palya;
    Spinbox * box;

public:
    Menu(int w_width, int w_height) : App(w_width, w_height)
    {
        //start menü -
        cim = new Static_pics(this,150,100,500,200,"cim","kepek/cim.csv");
        start = new Push_button(this,300,280,200,50,"play","kepek/Play_icon.csv","kepek/playkj.csv");
        exit = new Push_button(this,300,360,200,50,"exit","kepek/exit.csv","kepek/exitkj.csv");

        //Szintek
        _back = new Push_button(this,300,520,200,50,"back","kepek/back.csv","kepek/backkj.csv");
        easy = new Push_button(this,300,280,200,50,"easy","kepek/easy.csv","kepek/easykj.csv");
        medium = new Push_button(this,300,360,200,50,"medium","kepek/medium.csv","kepek/mediumkj.csv");
        hard = new Push_button(this,300,440,200,50,"hard","kepek/hard.csv","kepek/hardkj.csv");

        //pálya

        palya = new Field(this,125,200,550,550,"palya");

        vector<string> es;
        string line;
        ifstream e ("easy.txt");
        while(getline(e,line))
        {
            getline(e,line);
            es.push_back(line);
        }
        line = es[rand()%5000];
        cout << line[0];
        int x = 0;
        int k = 0;
        string c;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
        {
            {
                c = line[x];
                box = new Spinbox(this,125+j*61,200+i*61,60,60,"box",1,9,c);
                x++;
            }
        }

    }
};



int main()
{
    Menu * menu = new Menu(800,800);
    menu->menu_loop();
    return 0;

}
