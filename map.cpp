#include "map.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include "spinbox.hpp"

using namespace genv;

void Field::draw()
{
    gout << color(160,160,160) << move_to(_x-4,_y-4) << box(_sx+10,_sy+10);

    int k = 1;
    int l = 1;
       for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
        {

        if(j >= 3 ) k = 2;
        else k = 1;

        if(j >= 6) k = 3;

        if(i >= 3 ) l = 2;
        else l = 1;

        if(i >= 6) l = 3;

            gout << color(255,255,255) << move_to(_x+i*61+l,_y+j*61+k) << box(60,60);

        }
}



void Field::handle(genv::event ev){}
