#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include <algorithm>
#include "CS213-2023-Section1-Assignment3-20220835-20220334-20220854_BoardGame_Classes.hpp"
using namespace std;
FourInARowBoard::FourInARowBoard() {
    board = new char*[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        board[i] = new char[COLS];
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = ' ';
        }
    }
}

bool FourInARowBoard::update_board(int x, int y, char symbol) {
    // Check if the move is within valid bounds and the column is not full
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && board[x][y] == ' ') {
        // Find the lowest empty row in the selected column
        int row = ROWS - 1;
        while (row >= 0 && board[row][y] != ' ') {
            row--;
        }

        // Update the board with the player's symbol
        if (row >= 0) {
            board[row][y] = symbol;
            n_moves++;
            return true;
        }
    }
    return false;
}

void FourInARowBoard::display_board() {
    system("cls");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "(" << i << "," << j << ") ";
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool FourInARowBoard::is_winner() {
    // Check horizontally
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check vertically
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check diagonally (top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Check diagonally (top-right to bottom-left)
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 3; j < COLS; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3]) {
                return true;
            }
        }
    }

    return false;
}

bool FourInARowBoard::is_draw() {
    // Check if the board is full
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool FourInARowBoard::game_is_over() {
    return n_moves == ROWS * COLS || is_winner() || is_draw();
}
