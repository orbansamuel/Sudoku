#include "app.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>
using namespace genv;

void App::App_loop()
{
    bool out = false, game = false, level = false, menu = true;
    event ev;
    int fs = -1;
    gin.timer(0);
    while (gin >> ev && ev.keycode != key_escape)
    {
        int mouse_x = ev.pos_x;
        int mouse_y = ev.pos_y;

        if (menu && !game && !level)
        {
            gout << move_to(0, 0) << color(0, 0, 0) << box(_width, _height);

            if (ev.type == ev_mouse)
            {
                for (size_t i = 0; i < widgets.size(); i++)
                {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && (widgets[i]->_flag == "play" || widgets[i]->_flag == "exit"))
                    {
                        fs = i;
                        break;
                    }
                }
            }

            if (fs >= 0)
            {
                widgets[fs]->handle(ev);
            }
            else
            {
                fs = -1;
            }

            for (Widget *w : widgets)
            {
                if (w->_flag == "cim")
                    w->draw();
                if (w->_flag == "play")
                    w->draw();
                if (w->_flag == "exit")
                    w->draw();
            }

            gout << refresh;

            for (size_t i = 0; i < widgets.size(); i++)
            {
                if (click(ev, i, "exit", "menu"))
                {
                    out = true;
                    break;
                }
                else if (click(ev, i, "play", "menu"))
                {
                    level = true;
                    menu = false;
                    break;
                }
            }

            if (out == true)
                break;

        }

        if (level && !menu && !game)
        {
            gin.wait_event(ev);

            if (ev.type == ev_mouse)
            {
                for (size_t i = 0; i < widgets.size(); i++)
                {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && (widgets[i]->_flag == "easy" || widgets[i]->_flag == "back" || widgets[i]->_flag == "medium" || widgets[i]->_flag == "hard"))
                    {
                        fs = i;
                    }
                }
            }

            if (fs > 0)
            {
                widgets[fs]->handle(ev);
            }
            else
            {
                fs = -1;
            }

            for (Widget *w : widgets)
            {
                if (w->_flag == "cim")
                    w->draw();
                if (w->_flag == "back")
                    w->draw();
                if (w->_flag == "easy")
                    w->draw();
                if (w->_flag == "medium")
                    w->draw();
                if (w->_flag == "hard")
                    w->draw();
            }

            for (size_t i = 0; i < widgets.size(); i++)
            {
                if (click(ev, i, "back", "level"))
                {
                    level = false;
                    menu = true;
                    break;
                }
                else if (click(ev, i, "easy", "level") || click(ev, i, "medium", "level") || click(ev, i, "hard", "level"))
                {
                    game = true;
                    level = false;
                    break;
                }
            }
        }

        if (game && !level && !menu)
        {

            if (ev.type == ev_mouse || ev.type == ev_key)
            {
                for (size_t i = 0; i < widgets.size(); i++)
                {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && (widgets[i]->_flag == "box" || widgets[i]->_flag == "back2"))
                    {
                        fs = i;
                    }
                }
            }

            if (fs >= 0)
            {
                widgets[fs]->handle(ev);
            }

            for (Widget *w : widgets)
            {
                if (w->_flag == "palya")
                    w->draw();
                if (w->_flag == "box")
                    w->draw();
                if (w->_flag == "back2")
                    w->draw();
                if (w->_flag == "+oldva" && megoldva)
                    w->draw();
            }

            for (size_t i = 0; i < widgets.size(); i++)
            {
                if (click(ev, i, "back2", "game"))
                {
                    menu = true;
                    game = false;
                    break;
                }
            }
        }

        gout << refresh;
        for (Widget *w : widgets)
            {
                if (w->_flag == "friss")
                    w->draw();
            }
    }
}

bool App::click(genv::event ev, int loop, std::string name, std::string state)
{
    if (widgets[loop]->_flag == name && ev.button == btn_left && widgets[loop]->is_selected(ev.pos_x, ev.pos_y))
    {
        if (state == "menu" && (name == "play" || name == "exit"))
            return true;
        else if (state == "level" && (name == "back" || name == "easy" || name == "medium" || name == "hard"))
            return true;
        else if (state == "game" && (name == "back2"))
            return true;
    }
    return false;
}

