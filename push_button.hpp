#ifndef PUSH_BUTTON_HPP_INCLUDED
#define PUSH_BUTTON_HPP_INCLUDED

class Push_button : public Widget
{
protected:
    std::string _flag; //ezt azért raktam bele hogy könnyedén tudjak rá hivatkozni
    std::string _unselected;
    std::string _selected;
    std::string file ;

public:
    Push_button(App * a, int x, int y, int sx, int sy, std::string flag, std::string unselected_b, std::string selected_b):
        Widget(a,x,y,sx,sy,flag),_unselected(unselected_b),_selected(selected_b)
        {
            file = _unselected;
        }
        virtual void draw() override;
        virtual void handle(genv::event ev) override;
};

#endif // PUSH_BUTTON_HPP_INCLUDED
