#ifndef PUSH_BUTTON_HPP_INCLUDED
#define PUSH_BUTTON_HPP_INCLUDED

class Push_button : public Widget
{
protected:
    int _flag;
    std::string _filename;

public:
    Push_button(App * a, int x, int y, int sx, int sy, int flag, std::string filename ):
        Widget(a,x,y,sx,sy), _flag(flag),_filename(filename)
        {
            draw();
        }
        virtual void draw();
        virtual void handle(genv::event ev);
};

#endif // PUSH_BUTTON_HPP_INCLUDED
