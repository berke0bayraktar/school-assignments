#ifndef EXP1_BOARD_H
#define EXP1_BOARD_H
#include "constants.h"
#include "boardprinter.h"
#include "boardbuilder.h"

#include <iostream>

using namespace Consts;

class Board {
    friend class BoardBuilder;
    friend class BoardPrinter;

private:
    int open[SUIT_TYPE_NUM][CARDS_IN_SUIT_NUM];
    char pile[PILE_NUM][DECK_CARD_MAX][CARD_REP_SIZE];
    char foundation[SUIT_TYPE_NUM][DECK_CARD_MAX][CARD_REP_SIZE];
    char stock[STOCK_SIZE][CARD_REP_SIZE];

    char waste[STOCK_SIZE][CARD_REP_SIZE];
    char wasteSlot1[3];
    char wasteSlot2[3];

    int wasteSize = 0;
    int stockSize = STOCK_SIZE;

    int pileSizes[PILE_NUM] = {1, 2, 3, 4, 5, 6, 7};
    int foundationSizes[SUIT_TYPE_NUM] = {0,0,0,0};

    /* LOW LEVEL FUNCTIONS FOR CARD MANIPULATION*/
    void SLOT_TO_WASTE(char *slot);
    void WASTE_TO_SLOT(char* slot);
    void STOCK_TO_WASTE(int count);
    void PILE_TO_FND(int src, int fndIdx);
    void SLOT_TO_FND(char* slot, int fndIdx);
    void PILE_TO_PILE(int src, int dest, int count);
    void SLOT_TO_PILE(char* slot, int dest);
    void FND_TO_PILE(int fndIdx, int dest);
    void STOCK_TO_SLOT(char *slot);
    void REFILL();
    void WASTE_TO_FND(int fndIdx);


    /* UTIL FUNCTIONS */
    void C_MOVE(void* from, void* to, int cardCount);
    int C_EMPTY(const char* card);
    int C_PRED(const char* card1, const char* card2);
    int C_PRED_FND(const char* card, int fndIdx);
    int C_IS_OPEN(const char* card);
    void C_OPEN(const char* card);
    char C_SUIT(const char* card);
    int SUIT_TO_IDX(char suit);
    int C_VAL(const char* card);
    void C_MARK_EMPTY(void* ptr, int cardCount);

public:
    Board();
    /* HIGH LEVEL FUNCTIONS FOR GAME OPERATIONS*/
    void OpenFromStock();

    void MoveToFoundationFromPile(int pileIdx);
    void MoveToFoundationFromWaste();

    void MovePile(int pileSrc, int idx, int pileDest);
    void MoveWaste(int pileDest);
    void MoveFoundation(int srcFoundation, int pileDest);

    void Open(int pileIdx);

    int WinState();
};


#endif