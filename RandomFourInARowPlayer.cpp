#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"CS213-2023-Section1-Assignment3-20220835-20220334-20220854_BoardGame_Classes.hpp"
using namespace std;

// RandomFourInARowPlayer class definition
RandomFourInARowPlayer::RandomFourInARowPlayer(char symbol, int dimension) : FourInARowPlayer(symbol), dimension(dimension) {
    srand((unsigned int)(time(nullptr)));
}

// RandomFourInARowPlayer::get_move implementation
void RandomFourInARowPlayer::get_move(int& x, int& y, FourInARowBoard* board) {
    // Generate a random move within the specified dimensions
    y = rand() % dimension;
    // Assuming the bottom row is 0, adjust the row based on the current state of the column
    for (x = FourInARowBoard::ROWS - 1; x >= 0; --x) {
        if (board->board[x][y] == ' ') {
            // Found an empty space in the column, break the loop
            break;
        }
    }


}
