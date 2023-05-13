#include "widgets.hpp"
#include "app.hpp"
#include "push_button.hpp"
#include "graphics.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace genv;
using namespace std;
struct RGB
{
    int r,g,b;

};


std::vector<RGB> pics_read(const std::string& filename)
{
    std::vector<RGB> pics;
    std::ifstream file(filename);

    if (!file)
    {
        std::cout << "Nem sikerült megnyitni a fájlt." << std::endl;
        return pics;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string value;

        RGB pic;
        std::getline(iss, value, ';');
        pic.r = std::stoi(value);

        std::getline(iss, value, ';');
        pic.g = std::stoi(value);

        std::getline(iss, value, ';');
        pic.b = std::stoi(value);

        pics.push_back(pic);
    }

    file.close();

    return pics;
}

void Push_button::draw()
{
  vector<RGB> pics = pics_read(_filename);

  canvas c;
  c.open(_sx,_sy);
  int x = 0;
  for(int i = 0; i < _sy;i++)
  {
      for(int j = 0; j < _sx;j++)
      {

          c << move_to(i*4,j) << color(pics[x].r,pics[x].g,pics[x].b) << box(4,1);
          x += 1;
      }
  }

  gout << stamp(c,_x,_y);
}

void Push_button::handle(genv::event ev){}

