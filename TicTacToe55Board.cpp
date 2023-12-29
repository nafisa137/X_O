//TicTacToe55Board.cpp
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "CS213-2023-Section1-Assignment3-20220835-20220334-20220854_BoardGame_Classes.hpp"
using namespace std;

// Set the board
Tic_Tac_Toe::Tic_Tac_Toe() {
    n_rows = n_cols = 5;
    n_moves = 0; // Initialize the number of moves
    winCountPlayer1 = 0; // Initialize the win count for player 1
    winCountPlayer2 = 0; // Initialize the win count for player 2
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool Tic_Tac_Toe::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= n_rows || y < 0 || y >= n_cols) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;

        // Check for a win and update the win count
        if (is_winner()) {
            if (toupper(mark) == 'X') {
                winCountPlayer1++;
            } else {
                winCountPlayer2++;
            }
            cout << "Player: " << (toupper(mark) == 'X' ? "Player 1" : "Player 2") << " wins" << endl;
            display_board();
            cout << "Press Enter to exit..." << endl;
            cin.ignore();
            exit(0); // Exit the program
        }

        return true;
    } else
        return false;
}

void Tic_Tac_Toe::display_board() {
    for (int i = 0; i < n_rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-------------------------------";
    }
    cout << endl;
}

bool Tic_Tac_Toe::is_winner() {
    // Update the logic to check for three-in-a-row sequences in a 5x5 grid
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            // Check horizontally
            if (j + 2 < n_cols &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2]) {
                if (winCountPlayer1 == 5 || winCountPlayer2 == 5) {
                    return true;
                }
            }

            // Check vertically
            if (i + 2 < n_rows &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j]) {
                if (winCountPlayer1 == 5 || winCountPlayer2 == 5) {
                    return true;
                }
            }

            // Check diagonally (both directions)
            if (i + 2 < n_rows) {
                if (j + 2 < n_cols &&
                    board[i][j] == board[i + 1][j + 1] &&
                    board[i][j] == board[i + 2][j + 2]) {
                    if (winCountPlayer1 == 5 || winCountPlayer2 == 5) {
                        return true;
                    }
                }

                if (j - 2 >= 0 &&
                    board[i][j] == board[i + 1][j - 1] &&
                    board[i][j] == board[i + 2][j - 2]) {
                    if (winCountPlayer1 == 5 || winCountPlayer2 == 5) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Tic_Tac_Toe::is_draw() {
    return (n_moves == (n_rows * n_cols) && !is_winner());
}

bool Tic_Tac_Toe::game_is_over() {
    return n_moves == (n_rows * n_cols);
}

