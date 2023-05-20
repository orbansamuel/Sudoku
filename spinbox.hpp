#ifndef SPINBOX_HPP_INCLUDED
#define SPINBOX_HPP_INCLUDED

#include "widgets.hpp"
#include <functional>


class Spinbox : public Widget
{
protected:
    int _max;
    int _min;
    std::function<void()> _f;

    int _r,_g,_b = 0;
public:
    std::string _text,_szam;
    int _i;
    bool szin;

    Spinbox(App * a, int x,int y, int sx,int sy,std::string flag,int __min,int __max,std::string szam,std::function<void()> f):Widget(a,x,y,sx,sy,flag), _max(__max), _min(__min), _szam(szam),
    _f(f)
    {

        _text = szam;
        _i = stoi(_text);
    }
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual bool action()
    {
        _f();
    }


};


#endif // SPINBOX_HPP_INCLUDED
