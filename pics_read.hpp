#ifndef PICS_READ_HPP_INCLUDED
#define PICS_READ_HPP_INCLUDED
#include <iostream>
#include <vector>
struct RGB
{
    int r,g,b;

};

#include "pics_read.hpp"
#include <iostream>
#include <vector>



std::vector<RGB> pics_read(std::string filename);


#endif // PICS_READ_HPP_INCLUDED
