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
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 9; i++) {
        if(row != i && col != i)
        {
        if (_board[row * 9 + i] == num) return false;
        if(_board[i * 9 + col] == num) return false;
        if(_board[(startRow + i / 3) * 9 + startCol + i % 3] == num) return false;
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
