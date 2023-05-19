#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED
#include <vector>

class JatekMester
{
protected:
    int _index;
    std::vector<int> _board;
    int rowIndex;
    int colIndex;
public:
    JatekMester(int index) : _index(index)
    {
        int rowIndex = (index / 9) + 1;
        int colIndex = (index % 9) + 1;
    }
    void setValue(int row, int col, int value);
    int getValue(int row, int col);
    bool isMoveValid(int row, int col, int num);
    bool isSolved();
    void printBoard();



};

#endif // JATEKMESTER_HPP_INCLUDED
