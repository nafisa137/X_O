#include <iostream>
#include "CS213-2023-Section1-Assignment3-20220835-20220334-20220854_BoardGame_Classes.hpp"
#include "GameManager.hpp"
#include "Player.hpp"
#include "RandomPlayer.hpp"

using namespace std;

int main() {
    while (true) {
        srand((unsigned)(time(nullptr)));

        int choice, x;
        cout << "hello in to Tic Tac Toe Game. :)\n";
        cout << "Choose the type of the game:\n";
        cout << "1- Normal XO\n";
        cout << "2- Pyramid XO\n";
        cout << "3- Four-in-a-row XO\n";
        cout << "4- 5 x 5 XO\n";
        cout << "5- stop\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Player *players[2];
                players[0] = new Player(1, 'x');
                cout << "Welcome to FCAI X-O Normal version Game. :)\n";
                cout << "Press 1 if you want to play with computer: ";
                cin >> x;
                if (x != 1)
                    players[1] = new Player(2, 'o');
                else
                    players[1] = new RandomPlayer('o', 3);

                GameManager x_o_game(new X_O_Board(), players);
                x_o_game.run();
                break;
            }

            case 2: {
                int xx;
                Player *players[2];
                players[0] = new Player(1, 'x');
                cout << "Welcome to FCAI X-O Game. :)\n";
                cout << "Press 1 if you want to play with computer: ";
                cin >> xx;
                if (xx != 1)
                    players[1] = new Player(2, 'o');
                else
                    players[1] = new RandomPlayer('o', 3);

                GameManager x_o_game(new pyramid_XO_Board(), players);
                x_o_game.run();
                break;
            }
            case 3: {
                FourInARowPlayer *players[2];
                players[0] = new FourInARowPlayer(1, 'x');

                cout << "Welcome to FCAI X-O Four In Row version Game. :)\n";
                cout << "Press 1 if you want to play with computer: ";
                cin >> x;
                if (x != 1)
                    players[1] = new FourInARowPlayer(2, 'o');
                else
                    players[1] = new RandomFourInARowPlayer('o', 7);

                FourInARowGameManager Fourinrowmanager(new FourInARowBoard(), players);
                Fourinrowmanager.run();

                break;
            }
            case 4: {
                Tic_Tac_Toe game;
                string player1Name, player2Name;
                cout << "Welcome player 1" << endl;
                cout << "Please enter your name:";
                cin >> player1Name;

                cout << " Welcome to 5x5 Tic-Tac-Toe Game. :)" << endl;
                cout << "Press 1 if you want to play with the computer:0" << endl;

                cout << " Welcome player 2" << endl;
                cout << "Please enter your name:";
                cin >> player2Name;

                cout << endl;

                game.display_board();

                while (!game.game_is_over()) {
                    int x, y;
                    cout << "Please enter your move x and y (0 to 4) separated by spaces:";
                    cin >> x >> y;

                    if (game.update_board(x, y, 'X')) {
                        game.display_board();
                    }

                    // Random computer player's move
                    int compX, compY;
                    do {
                        compX = rand() % 5;
                        compY = rand() % 5;
                    } while (!game.update_board(compX, compY, 'O'));

                    game.display_board();
                }
                break;
            }

            case 5: {
                return 0;
            }

            default: {
                cout << "Please enter a valid input\n";
                return 0;
            }
        }
    }

    return 0;
}
