#include "app.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

void App::event_loop()
{

    event ev;
    int fs = -1;
    while(gin >> ev)
    {

        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        fs = i;
                }
            }
        }
        if (fs>=0) {
            widgets[fs]->handle(ev);
        }

        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;


    }
}

void App::open(int XX, int YY)
{
    genv::gout.open(XX,YY);

}
