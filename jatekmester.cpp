#include "jatekmester.hpp"
#include <iostream>
#include <vector>
#include "spinbox.hpp"
#include "graphics.hpp"

using namespace genv;
void JatekMester::setValue(int value) {
   // _board[_index] = value;
}

int JatekMester::getValue(int row, int col) {
    int index = row * 9 + col;
   // return _board[_index];
}

bool JatekMester::isMoveValid(int row, int col, int num,int index) {
    int startRow = (row/3) * 3;
    int startCol = (col/3) * 3;

    for(int i = 0; i < 9; i++)
    {
        if(i != col && _board[row*9 +i] == num) return false;
    }

    for(int i = 0; i < 9; i++)
    {
        if(i != row && _board[i*9+col] == num) return false;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int rowIndex = startRow + i;
            int colIndex = startCol + j;
            int boxIndex = rowIndex * 9 + colIndex;

            if (boxIndex != index && _board[boxIndex] == num) {
                return false;
            }
        }
    }


    return true;
}

bool JatekMester::isSolved() {
    for (int num : _board) {
        if (num == 0) {
            return false;
        }
    }
    return true;
}


void JatekMester::GetIndex(std::vector<Spinbox*> s,genv::event ev,int &k)
{
    int i = 0;
    for(Spinbox *b : s)
    {

        if(b->is_selected(ev.pos_x,ev.pos_y))
        {
                k = i;
        }

        i++;
    }

}
