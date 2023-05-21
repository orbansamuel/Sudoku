#include "update.hpp"
#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;

void UpD::draw()
{
  gout << color(0,0,0) << move_to(_x,_y) << box(_sx,_sy);


}



void UpD::handle(genv::event ev){}
