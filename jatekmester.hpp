#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED
#include <vector>
#include "spinbox.hpp"
class JatekMester
{
protected:
    int rowIndex;
    int colIndex;
public:
    std::vector<int> _board;
    JatekMester()
    {
    }
    int GetRow(int index)
    {
       return (index / 9);
    }
    int GetCol(int index)
    {
       return (index % 9);
    }
    bool isMoveValid(int row, int col, int num,int index);




};

#endif // JATEKMESTER_HPP_INCLUDED
