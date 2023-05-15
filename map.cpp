#include "map.hpp"
#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;

void Field::draw()
{
    gout << color(160,160,160) << move_to(_x-4,_y-4) << box(_sx+10,_sy+10);
    /*gout << color(255,255,255) << move_to(_x,_y) << box(_sx,_sy);
    gout << color (160,160,160) << move_to(_x+_sx/3,_y) << box(2,_sy);
    gout << color (160,160,160) << move_to(_x+2*_sx/3,_y) << box(2,_sy);
    gout << color (160,160,160) << move_to(_x,_y+_sy/3) << box(_sx,2);
    gout << color (160,160,160) << move_to(_x,_y+2*_sy/3) << box(_sx,2);

    gout << color (16,160,160) << move_to(_x+_sx/9,_y) << box(1,_sy);
    gout << color (16,160,160) << move_to(_x+2*_sx/9,_y) << box(1,_sy);

    gout << color (16,160,160) << move_to(_x+5*_sx/9,_y) << box(1,_sy);
    gout << color (16,160,160) << move_to(_x+4*_sx/9,_y) << box(1,_sy);

    gout << color (16,160,160) << move_to(_x+7*_sx/9,_y) << box(1,_sy);
    gout << color (16,160,160) << move_to(_x+8*_sx/9,_y) << box(1,_sy);

    gout << color (16,160,160) << move_to(_x,_y+_sy/9) << box(_sx,1);
    gout << color (16,160,160) << move_to(_x,_y+2*_sy/9) << box(_sx,1);

    gout << color (16,160,160) << move_to(_x,_y+4*_sy/9) << box(_sx,1);
    gout << color (16,160,160) << move_to(_x,_y+5*_sy/9) << box(_sx,1);

    gout << color (16,160,160) << move_to(_x,_y+7*_sy/9) << box(_sx,1);
    gout << color (16,160,160) << move_to(_x,_y+8*_sy/9) << box(_sx,1);
*/

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
