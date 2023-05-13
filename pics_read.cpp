#include "pics_read.hpp"
#include <fstream>
#include <sstream>

std::vector<RGB> pics_read(std::string filename)
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
