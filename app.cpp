#include "app.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

void App::menu_loop()
{
    bool out = false,game = false, level = false;
    event ev;
    int fs = -1;
    while(gin >> ev)
    {
//&& ev.button==btn_left
        if(!level)
        {
            gout << move_to(0,0) << color(0,0,0) << box(_width,_height);

            if (ev.type == ev_mouse ) {
                for (size_t i=0;i<widgets.size();i++) {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                            fs = i;
                           // std::cout << fs << std::endl;
                    }

                }
            }
            if (fs>0) {
                widgets[fs]->handle(ev);
            }
            else fs = -1;

            for (Widget * w : widgets) {
                if(w->_flag == "cim" ) w->draw();
                if(w->_flag == "play" ) w->draw();
                if(w->_flag == "exit" ) w->draw();
            }
            gout << refresh;

            //std::cout << fs << std::endl;
            for (size_t i=0;i<widgets.size();i++) {
                if(widgets[i]->_flag == "exit" && ev.button == btn_left && widgets[i]->is_selected(ev.pos_x, ev.pos_y)){
                        out = true ;
                        break;
                }
                else if(widgets[i]->_flag == "play" && ev.button == btn_left && widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    level = true;
                }

            }
            if(out == true) break;
        }



        if(level && !game)
        {
            gout << move_to(0,0) << color(0,0,0) << box(_width,_height);

             if (ev.type == ev_mouse ) {
                for (size_t i=0;i<widgets.size();i++) {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                            fs = i;
                           // std::cout << fs << std::endl;
                    }

                }
            }
            if (fs>0) {
                widgets[fs]->handle(ev);
            }
            else fs = -1;

            for (Widget * w : widgets) {
                if(w->_flag == "cim" ) w->draw();
                if(w->_flag == "back" ) w->draw();
                if(w->_flag == "easy" ) w->draw();
                if(w->_flag == "medium" ) w->draw();
                if(w->_flag == "hard" ) w->draw();
            }

                        for (size_t i=0;i<widgets.size();i++) {
                if(widgets[i]->_flag == "back" && ev.button == btn_left && widgets[i]->is_selected(ev.pos_x, ev.pos_y)){
                        level = false ;
                        break;
                }

            }

            gout << refresh;
        }
    }
}


