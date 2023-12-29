#include "CS213-2023-Section1-Assignment3-20220835-20220334-20220854_BoardGame_Classes.hpp"
#include "X_O_Board.hpp"
#include <iostream>

using namespace std;

pyramid_XO_Board::pyramid_XO_Board() {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}

bool pyramid_XO_Board::update_board(int x, int y, char mark) {
    // Only update if the move is valid
    if (board[x][y] == ' ' && ((x == 0 && y == 2) || (x == 1 && y == 1) || (x == 1 && y == 2) || (x == 1 && y == 3) ||
                               (x == 2 && y == 0) || (x == 2 && y == 1) || (x == 2 && y == 2) || (x == 2 && y == 3) || (x == 2 && y == 4))) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else {
        return false;
    }
}

void pyramid_XO_Board::display_board() {
    // Display the board
    cout << "              |(0,2)" << board[0][2] << "|" << endl;
    cout << "       |(1,1)" << board[1][1] << "|(1,2)" << board[1][2] << "|(1,3)" << board[1][3] << "|" << endl;
    cout << "  |(2,0)" << board[2][0] << "|(2,1)" << board[2][1] << "|(2,2)" << board[2][2] << "|(2,3)" << board[2][3]
         << "|(2,4)" << board[2][4] << "|" << endl;
    cout << "\n----------------------------------------------------------" << endl;
}

bool pyramid_XO_Board::is_winner() {
    // Check for the 4 possible horizontal lines
    if ((board[1][1] == board[1][2] && board[1][2] == board[1][3] && board[1][1] != ' ' && board[1][2] != ' ' &&
         board[1][3] != ' ') ||
        (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != ' ' && board[2][1] != ' ' &&
         board[2][2] != ' ') ||
        (board[2][1] == board[2][2] && board[2][2] == board[2][3] && board[2][1] != ' ' && board[2][2] != ' ' &&
         board[2][3] != ' ') ||
        (board[2][2] == board[2][3] && board[2][3] == board[2][4] && board[2][2] != ' ' && board[2][3] != ' ' &&
         board[2][4] != ' ')) {
        return true;
    }
    // Check for the 1 possible vertical line
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != ' ' && board[1][2] != ' ' &&
        board[2][2] != ' ') {
        return true;
    }
    // Check for the 2 possible diagonal lines
    if ((board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[0][2] != ' ' && board[1][3] != ' ' &&
         board[2][4] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ' && board[1][1] != ' ' &&
         board[2][0] != ' ')) {
        return true;
    }
    return false;
}

bool pyramid_XO_Board::game_is_over() {
    return n_moves >= 9;
}

bool pyramid_XO_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}
