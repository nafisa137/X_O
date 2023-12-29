//FourInARowPlayer.cpp
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "CS213-2023-Section1-Assignment3-20220835-20220334-20220854_BoardGame_Classes.hpp"
using namespace std;

FourInARowPlayer::FourInARowPlayer(char symbol) : Player(symbol) {}

FourInARowPlayer::FourInARowPlayer(int order, char symbol) : Player(order, symbol) {}

void FourInARowPlayer::get_move(int& x, int& y, FourInARowBoard* board) {
    cout << "Player " << get_symbol() << "'s turn." << endl;

    while (true) {
        cout << "Enter your move (column number): ";
        cin >> y;

        // Assuming the bottom row is 0, adjust the row based on the current state of the column
        for (x = FourInARowBoard::ROWS - 1; x >= 0; --x) {
            if (board->board[x][y] == ' ') {
                // Found an empty space in the column, break the loop
                break;
            }
        }

        // Validate the move to be within the board boundaries
        if (x >= 0 && x < FourInARowBoard::ROWS && y >= 0 && y < FourInARowBoard::COLS && board->board[x][y] == ' ') {
            break; // Valid input, break out of the loop
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }
}
