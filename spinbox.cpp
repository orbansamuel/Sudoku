#include "graphics.hpp"
#include "spinbox.hpp"
#include "app.hpp"
#include <iostream>
#include <string>

using namespace genv;
void Spinbox::handle(genv::event ev)
{
    if(is_selected(ev.pos_x,ev.pos_y) && _szam == "0") _c = 255;
    else _c = 0;




        if (ev.keycode == 65536 && _i < _max) {
            _i++;
        }
        else if (ev.keycode == key_down && _i > _min) {
            _i--;
        }

        if (ev.button == btn_wheelup && _i < _max) {
            _i++;
        } else if (ev.button == btn_wheeldown && _i > _min) {
            _i--;
        }

if(ev.type == ev_key)
{

        if(ev.keyname == "1") _i = 1;
        else if(ev.keyname == "2") _i = 2;
        else if(ev.keyname == "3") _i = 3;
        else if(ev.keyname == "4") _i = 4;
        else if(ev.keyname == "5") _i = 5;
        else if(ev.keyname == "6") _i = 6;
        else if(ev.keyname == "7") _i = 7;
        else if(ev.keyname == "8") _i = 8;
        else if(ev.keyname == "9") _i = 9;
        std::cout << ev.keyname << std::endl;
}

    _text = std::to_string(_i);
}

void Spinbox::draw()
{
    if(_szam == "0")
    {
    gout << color(_c,200,0) << move_to(_x+_sx/4,_y+_sy/3) << text(_text);
    }
    else
    {
        gout.load_font("cool.ttf",30);
        gout << color(0,0,0) << move_to(_x+_sx/4,_y+_sy/3) << text(_szam);
    }
}




bool Spinbox::up(genv::event ev)
{
    if(ev.pos_x > _x+_sx-_sx/4-15 && ev.pos_x < _x+_sx-_sx/4+15 &&
       ev.pos_y > _y+_sy/4-15 && ev.pos_y < _y+_sy/4+15 && ev.button == btn_left)
    {
        return true;
    }
    return false;
}

bool Spinbox::down(genv::event ev)
{
     if(ev.pos_x > _x+_sx-_sx/4-15 && ev.pos_x < _x+_sx-_sx/4+12
        && ev.pos_y > _y+_sy-_sy/3-5 && ev.pos_y < _y+_sy-_sy/3 + 30 && ev.button == btn_left)
    {
        return true;
    }
    return false;

}




