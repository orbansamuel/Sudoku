#include "app.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

void App::menu_loop()
{
    bool out = false,game = false, level = false,menu = true;
    event ev;
    int fs = -1;
    gin.timer(0);
    while(gin >> ev)
    {
//&& ev.button==btn_left
        if(menu)
        {
            gout << move_to(0,0) << color(0,0,0) << box(_width,_height);

            if (ev.type == ev_mouse )
            {
                for (size_t i=0;i<widgets.size();i++)
                {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && (widgets[i]->_flag == "play" || widgets[i]->_flag == "exit" ))
                    {
                        fs = i;
                        // std::cout << fs << std::endl;
                        break;
                    }

                }
            }

            if (fs>=0)
            {
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
                if(click(ev,i,"exit","menu"))
                {
                        out = true ;
                        break;
                }
                else if(click(ev,i,"play","menu"))
                {
                    level = true;
                    menu = false;
                    break;
                }

            }
            if(out == true) break;

        }



        if(level)
        {
            gin.wait_event(ev);
           // std::cout << "itt voltam" << std::endl;
            gout << move_to(0,0) << color(0,0,0) << box(_width,_height);

             if (ev.type == ev_mouse )
             {
                for (size_t i=0;i<widgets.size();i++)
                 {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && (widgets[i]->_flag == "easy" || widgets[i]->_flag == "back" || widgets[i]->_flag == "medium" || widgets[i]->_flag == "hard"  ))
                    {
                        fs = i;
                        // std::cout << fs << std::endl;
                    }
                 }
             }

            if (fs>0 )
            {
                widgets[fs]->handle(ev);
            }
            else fs = -1;

            for (Widget * w : widgets)
            {
                if(w->_flag == "cim" ) w->draw();
                if(w->_flag == "back" ) w->draw();
                if(w->_flag == "easy" ) w->draw();
                if(w->_flag == "medium" ) w->draw();
                if(w->_flag == "hard" ) w->draw();
            }

            for (size_t i=0;i<widgets.size();i++)
            {
                if(click(ev,i,"back","level"))
                {
                    level = false;
                    menu = true;
                    break;
                }
                else if(click(ev,i,"easy","level"))
                {
                        game = true;
                        break;
                }
            }
        }



            if(game)
            {
                //std::cout << "itt vagyok" << std::endl;
                gout << move_to(0,0) << color(0,0,0) << box(_width,_height);

                if (ev.type == ev_mouse ) {
                    for (size_t i=0;i<widgets.size();i++) {
                        if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                                fs = i;
                               // std::cout << fs << std::endl;
                        }

                    }
                for(Widget * w : widgets)
                {
                    if(w->_flag == "palya") w->draw();
                    if(w-> _flag == "box") w->draw();
                }
            }
            }

            gout << refresh;
    }
}


bool App::click(genv::event ev,int loop,std::string name,std::string state)
{

    if (widgets[loop]->_flag == name && ev.button == btn_left && widgets[loop]->is_selected(ev.pos_x, ev.pos_y))
    {
        if (state == "menu" && (name == "play" || name == "exit"))
            return true;
        else if (state == "level" && (name == "back" || name == "easy" || name == "medium" || name == "hard"))
            return true;
     }
     else{ return false;}
}
