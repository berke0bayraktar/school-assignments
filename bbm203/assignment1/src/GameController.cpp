//
// Created by berke on 13.11.2020.
//

#include "GameController.h"

//todo: exit condition
void GameController::ExecuteCommand(Board* board, const std::string& method, const int *params) {
    if (method == "open from stock") {
        board->OpenFromStock();
    }
    else if (method == "move to foundation pile") {
        int pileIdx = params[0];
        board->MoveToFoundationFromPile(pileIdx);
    }
    else if(method == "move to foundation waste") {
        board->MoveToFoundationFromWaste();
    }
    else if (method == "move pile") {
        int pileSrc = params[0], idx = params[1], pileDest = params[2];
        board->MovePile(pileSrc, idx, pileDest);
    }
    else if (method == "move waste") {
        int pileDest = params[0];
        board->MoveWaste(pileDest);
    }
    else if (method == "move foundation") {
        int srcFoundation = params[0], pileDest = params[1];
        board->MoveFoundation(srcFoundation, pileDest);
    }
    else if (method == "open") {
        int pileIdx = params[0];
        board->Open(pileIdx);
    }
}

int GameController::WinState(Board &board) {
    return board.WinState();
}
