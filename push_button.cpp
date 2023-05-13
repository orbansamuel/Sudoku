#include "widgets.hpp"
#include "app.hpp"
#include "push_button.hpp"
#include "graphics.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include "pics_read.hpp"

using namespace genv;
using namespace std;


void Push_button::draw()
{
  vector<RGB> pics = pics_read(_filename);

  canvas c;
  c.open(_sx,_sy);
  int x = 0;
  for(int i = 0; i < _sx;i++)
  {
      for(int j = 0; j < _sy;j++)
      {

          c << move_to(i,j) << color(pics[x].r,pics[x].g,pics[x].b) << box(1,1);
          x += 1;
      }
  }

  gout << stamp(c,_x,_y);
}

void Push_button::handle(genv::event ev){}

