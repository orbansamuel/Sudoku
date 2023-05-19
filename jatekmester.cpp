#include "jatekmester.hpp"
#include <iostream>


void JatekMester::setValue(int row, int col, int value) {
    _board[_index] = value;
}

int JatekMester::getValue(int row, int col) {
    int index = row * 9 + col;
    return _board[_index];
}

bool JatekMester::isMoveValid(int row, int col, int num) {
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 9; i++) {
        if (_board[row * 9 + i] == num || _board[i * 9 + col] == num ||
            _board[(startRow + i / 3) * 9 + startCol + i % 3] == num) {
            return false;
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

