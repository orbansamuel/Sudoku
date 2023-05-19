#ifndef PUSH_BUTTON_HPP_INCLUDED
#define PUSH_BUTTON_HPP_INCLUDED

#include <functional>

class Push_button : public Widget
{
protected:
    std::string _unselected;
    std::string _selected;
    std::string file ;

public:
    Push_button(App * a, int x, int y, int sx, int sy, std::string flag, std::string unselected_b, std::string selected_b):
        Widget(a,x,y,sx,sy,flag),_unselected(unselected_b),_selected(selected_b)
        {
            file = _unselected;
        };
        virtual void draw() override;
        virtual void handle(genv::event ev) override;
};


class Funktor_Button : public Push_button
{
protected:
    std::function<void()> _f;
public:
    Funktor_Button(App * a,int x,int y, int sx,int sy, std::string flag, std::string unselect, std::string select,std::function<void()> f) :
        Push_button(a,x,y,sx,sy,flag,unselect,select) , _f(f){};

        virtual void action()
        {
            _f();
        }
        virtual void handle(genv::event ev);

};

#endif // PUSH_BUTTON_HPP_INCLUDED
