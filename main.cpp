#include "graphics.hpp"
#include "widgets.hpp"
#include "app.hpp"
#include "push_button.hpp"
#include <iostream>
#include "static_pics.hpp"

using namespace genv;

class App;

struct Menu : public App
{
protected:
    Push_button * start;
    Push_button * exit;
    Static_pics * cim;
public:
    Menu(int w_width, int w_height) : App(w_width, w_height)
    {
        cim = new Static_pics(this,150,100,500,200,"cim.csv");
        start = new Push_button(this,300,280,200,50,1,"Play_icon.csv");
        //gout << move_to(500,200) << color(255,255,255) << box(200,50);
        exit = new Push_button(this,300,360,200,50,2,"exit.csv");
    }
};

struct JatekMester
{

};

int main()
{
    Menu * menu = new Menu(800,800);
    menu->event_loop();

    return 0;

}
