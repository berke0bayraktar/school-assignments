#ifndef EXP1_BOARDBUILDER_H
#define EXP1_BOARDBUILDER_H


#include "constants.h"
#include "board.h"



using namespace Consts;

class Board; //forward declaration

class BoardBuilder {
public:
    static Board Build(char deck[TOTAL_CARD_NUM][CARD_REP_SIZE]);
};

#endif
