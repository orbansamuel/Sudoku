#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class App;

class Widget{
protected:
    App * _app;
    int _x ,_y, _sx, _sy;


public:
    std::string _flag;
    Widget(App* a, int x,int y, int sx, int sy,std::string flag);
    virtual bool is_selected(int mouse_x,int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;

};

#endif // WIDGETS_HPP_INCLUDED
