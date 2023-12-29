//CS213-2023-Section1-Assignment3-20220835-20220334-20220854_BoardGame_Classes.hpp

// Class definition for XO game classes
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
#include<string>
using namespace std;

class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board (int x, int y, char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner() = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board : public Board {
public:
    X_O_Board();
    bool update_board(int x, int y, char mark) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;
};
///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player{
protected:
    string name;
    char symbol;
public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player (char symbol); // Needed for computer players
    Player (int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    RandomPlayer (char symbol, int dimension);
    // Generate a random move
    void get_move(int& x, int& y);
};

///////////////////////////////////////////
class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end

};

class pyramid_XO_Board : public Board {
public:
    pyramid_XO_Board();
    bool update_board(int x, int y, char mark) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;
};

class Tic_Tac_Toe : public Board {
public:
    Tic_Tac_Toe();
    bool update_board(int x, int y, char mark) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;

private:
    int n_moves; // Track the total number of moves
    int winCountPlayer1; // Track the win count for player 1
    int winCountPlayer2; // Track the win count for player 2
};

class FourInARowBoard : public Board {
private:
    static const int ROWS = 6;
    static const int COLS = 7;
    char** board;

public:
    FourInARowBoard();
    bool update_board(int x, int y, char symbol) ;
    void display_board() ;
    bool is_winner() ;
    bool is_draw() ;
    bool game_is_over() ;
    friend class FourInARowPlayer;
    friend class RandomFourInARowPlayer;

};
class FourInARowPlayer : public Player {
public:
    FourInARowBoard* boardPtr;
    FourInARowPlayer(char symbol);
    FourInARowPlayer(int order, char symbol);
    virtual void get_move(int& x, int& y, FourInARowBoard* board) ;
};
class RandomFourInARowPlayer : public FourInARowPlayer {
public:
    RandomFourInARowPlayer(char symbol, int dimension);
    void get_move(int& x, int& y, FourInARowBoard* board)  ;
private:
    int dimension;
};

class FourInARowGameManager {
private:
    FourInARowBoard* boardPtr;
    FourInARowPlayer* players[2];

public:
    FourInARowGameManager(FourInARowBoard* bPtr, FourInARowPlayer* playerPtr[2]);
    void run();
};




#endif

