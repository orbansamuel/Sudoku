#ifndef UPDATE_HPP_INCLUDED
#define UPDATE_HPP_INCLUDED
#include "widgets.hpp"
class UpD : public Widget
{
protected:

public:
    UpD(App *a,int x,int y,int sx,int sy,std::string flag) : Widget(a,x,y,sx,sy,flag){}

    virtual void draw();
    virtual void handle(genv::event ev);


};

#endif // UPDATE_HPP_INCLUDED
