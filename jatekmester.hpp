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
    void setValue(int index);
    int GetRow(int index)
    {
       return (index / 9);
    }
    int GetCol(int index)
    {
       return (index % 9);
    }
    void GetIndex(std::vector<Spinbox*> s,genv::event ev,int &k);
    int getValue(int row, int col);
    bool isMoveValid(int row, int col, int num,int index);
    bool isSolved();
    void printBoard();



};

#endif // JATEKMESTER_HPP_INCLUDED
