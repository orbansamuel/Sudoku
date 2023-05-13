#include "widgets.hpp"
#include "app.hpp"
#include "push_button.hpp"
#include "graphics.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include "static_pics.hpp"
#include "pics_read.hpp"
using namespace genv;
using namespace std;




void Static_pics::draw()
{
  vector<RGB> pics = pics_read(_filename);

  canvas c;
  c.open(_sx,_sy);
  int l = 0;
  for(int i = 0; i < _sx;i++)
  {
      for(int j = 0; j < _sy;j++)
      {

          c << move_to(i,j) << color(pics[l].r,pics[l].g,pics[l].b) << box(1,1);
          l += 1;
      }
  }

  gout << stamp(c,_x,_y);

}

void Static_pics::handle(genv::event ev){}
