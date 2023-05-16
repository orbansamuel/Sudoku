#include "graphics.hpp"
#include "spinbox.hpp"
#include "app.hpp"
#include <iostream>

using namespace genv;
void Spinbox::handle(genv::event ev)
{


    if (up(ev) && _i < _max) {
        _i++;
    }
    else if (down(ev) && _i > _min) {
        _i--;
    }
    else if (ev.type == ev_key)
    {

        if (ev.keycode == 65536 && _i < _max) {
            _i++;
        }
        else if (ev.keycode == key_down && _i > _min) {
            _i--;
        }
    }
    else if (ev.type == ev_mouse) {
        if (ev.button == btn_wheelup && _i < _max) {
            _i++;
        } else if (ev.button == btn_wheeldown && _i > _min) {
            _i--;
        }
    }
    _text = std::to_string(_i);
}

void Spinbox::draw()
{

    gout << color(0,0,0) << move_to(_x+_sx-_sx/4,_y+_sy/4) << text("+");
    gout << color(0,0,0) << move_to(_x+_sx-_sx/4,_y+_sy-_sy/4) << text("_");

    gout << color(0,200,0) << move_to(_x+_sx/4,_y+_sy/3) << text(_text);

}




bool Spinbox::up(genv::event ev)
{
    if(ev.pos_x > _x+_sx-_sx/4-10 && ev.pos_x < _x+_sx-_sx/4+12 &&
       ev.pos_y > _y+_sy/4-10 && ev.pos_y < _y+_sy/4+12 && ev.button == btn_left)
    {
        return true;
    }
    return false;
}

bool Spinbox::down(genv::event ev)
{
     if(_x+_sx+4-_sx/3 < ev.pos_x && _y+_sy/2+1 < ev.pos_y && _x+_sx+4+_sx/3 > ev.pos_x && _y+_sy > ev.pos_y && ev.button == btn_left)
    {
        return true;
    }
    return false;

}




