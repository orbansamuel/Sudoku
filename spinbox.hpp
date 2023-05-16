#ifndef SPINBOX_HPP_INCLUDED
#define SPINBOX_HPP_INCLUDED

#include "widgets.hpp"



class Spinbox : public Widget
{
protected:
    std::string _text;
    int _max;
    int _min;
    int _i;
    int _c;

public:
    Spinbox(App * a, int x,int y, int sx,int sy,std::string flag,int __min,int __max):Widget(a,x,y,sx,sy,flag), _max(__max), _min(__min)
    {
        _i = _min;
        _text = std::to_string(_i);
    }
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual bool up(genv::event ev);
    virtual bool down(genv::event ev);


};


#endif // SPINBOX_HPP_INCLUDED
