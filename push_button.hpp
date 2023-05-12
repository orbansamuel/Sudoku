#ifndef PUSH_BUTTON_HPP_INCLUDED
#define PUSH_BUTTON_HPP_INCLUDED

class Push_button : public Widget
{
protected:
    std::string _text;

public:
    Push_button(App * a, int x, int y, int sx, int sy, std::string text):
        Widget(a,x,y,sx,sy), _text(text)
        {
            draw();
        }
        virtual void draw();
        virtual void handle(genv::event ev);
};

#endif // PUSH_BUTTON_HPP_INCLUDED
