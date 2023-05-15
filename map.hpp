#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED
#include "widgets.hpp"

class Field : public Widget
{
protected:

public:
    Field(App *a,int x,int y,int sx,int sy,std::string flag) : Widget(a,x,y,sx,sy,flag){}

    virtual void draw();
    virtual void handle(genv::event ev);


};

#endif // MAP_HPP_INCLUDED
