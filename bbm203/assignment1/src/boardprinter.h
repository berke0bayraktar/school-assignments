#ifndef EXP1_BOARDPRINTER_H
#define EXP1_BOARDPRINTER_H

#include "board.h"
#include "constants.h"
#include <fstream>
#define SECRET "@@@"
#define EMPTY "___"
#define ONE_SPACE " "
#define THREE_SPACE "   "
#define NINE_SPACE "         "

class Board;
class BoardPrinter {
public:
    static void Print(Board* board, std::ofstream& outputFile);
};

#endif