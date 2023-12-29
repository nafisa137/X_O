#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CS213-2023-Section1-Assignment3-20220835-20220334-20220854_BoardGame_Classes.hpp"

using namespace std;

// Set the board
X_O_Board::X_O_Board() {
    n_rows = n_cols = 3;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}

// Return true if move is valid and put it on the board
// within board boundaries in an empty cell
// Return false otherwise
bool X_O_Board::update_board(int x, int y, char mark) {
    // Only update if the move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == ' ')) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else {
        return false;
    }
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
    for (int i : {0, 1, 2}) {
        cout << "\n| ";
        for (int j : {0, 1, 2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
bool X_O_Board::is_winner() {
    for (int i : {0, 1, 2}) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return true;
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over() {
    return n_moves >= 9;
}
