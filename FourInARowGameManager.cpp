    #include <iostream>
    #include"CS213-2023-Section1-Assignment3-20220835-20220334-20220854_BoardGame_Classes.hpp"
    using namespace std;
FourInARowGameManager::FourInARowGameManager(FourInARowBoard* bPtr, FourInARowPlayer* playerPtr[2]) : boardPtr(bPtr) {
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void FourInARowGameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->get_move(x, y,boardPtr);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                players[i]->get_move(x, y,boardPtr);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()) {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}
