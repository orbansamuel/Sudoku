#include "graphics.hpp"
#include "widgets.hpp"
#include "app.hpp"
#include "push_button.hpp"
#include <iostream>


using namespace genv;

class App;

struct Menu : public App
{
protected:
    Push_button * pb1;
    Push_button * pb2;

public:
    Menu(int w_width, int w_height) : App(w_width, w_height)
    {
        pb1 = new Push_button(this,300,200,200,50,1,"Play_icon.csv");
        //gout << move_to(500,200) << color(255,255,255) << box(200,50);
        pb2 = new Push_button(this,300,280,200,50,2,"exit.csv");
    }
};

int main()
{
    Menu * menu = new Menu(800,800);
    menu->event_loop();

    return 0;

}
