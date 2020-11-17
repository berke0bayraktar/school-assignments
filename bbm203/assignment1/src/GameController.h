#ifndef EXP1_GAMECONTROLLER_H
#define EXP1_GAMECONTROLLER_H

#include "board.h"
#include <string>
class GameController {
public:
    static void ExecuteCommand(Board* board, const std::string& method, const int* params);
    static int WinState(Board& board);
};

#endif