#ifndef APP_HPP_INCLUDED
#define APP_HPP_INCLUDED

#include <vector>
#include "widgets.hpp"
#include <string>


class App
{
protected:
   std::vector<Widget*> widgets;
    int _width,_height;
public:
    App(int width,int height) : _width(width), _height(height)
    {
        genv::gout.open(width,height);
    }
    void add_widget(Widget * w) {widgets.push_back(w);}
    void menu_loop();
    bool click(genv::event ev,int loop,std::string name,std::string state);

    //virtual void app_event();

};

#endif // APP_HPP_INCLUDED
