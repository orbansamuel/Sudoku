#include "widgets.hpp"
#include "graphics.hpp"
#include "app.hpp"

using namespace genv;

Widget::Widget(App * a, int x, int y,int sx, int sy) : _app(a), _x(x), _y(y), _sx(sx), _sy(sy)
{
    _app -> add_widget(this);
}

bool Widget::is_selected(int mouse_x,int mouse_y)
{
    if(mouse_x > _x && mouse_x < _x+_sx &&
           mouse_y > _y && mouse_y < _x+_sy) return true;
    else return false;
}
