#include "graphics.hpp"
#include "spinbox.hpp"
#include "app.hpp"
#include <iostream>
#include <string>

using namespace genv;
void Spinbox::handle(genv::event ev)
{
       if(is_selected(ev.pos_x,ev.pos_y)) action();


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
        //std::cout << ev.keyname << std::endl;
}
    if(_szam == "0") _text = std::to_string(_i);
    else _text = _szam;

    //std::cout << _text << std::endl;
}

void Spinbox::draw()
{

    if(szin == false)
    {
        _r = 255;
        _g = 0;
    }
    else if(szin == true)
    {
        _g = 255;
        _r = 0;

    }
    gout.load_font("cool.ttf",30);
    if(_szam == "0" and _text == "0") gout << color(0,150,255) << move_to(_x+_sx/4,_y+_sy/3) << text(" ");
    else if(_szam == "0") gout << color(_r,_g,_b) << move_to(_x+_sx/4,_y+_sy/3) << text(_text);
    else gout << color(0,0,0) << move_to(_x+_sx/4,_y+_sy/3) << text(_szam);


}





