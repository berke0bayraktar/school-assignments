#include "boardbuilder.h"
#include "cstring"
using namespace Consts;

/* deck: cards received from deck.txt file
 * This function should:
 * 1) separate the cards to stock and 7 piles
 * 2) mark the necessary cards "open" (just for initialisation)
 * note: index 0 represents top of the stack in "deck"
 * */

Board BoardBuilder::Build(char deck[TOTAL_CARD_NUM][CARD_REP_SIZE]) {
    Board board;

    // import the 7 piles
    for(int i=0; i<7; i++){
        for(int j=i; j<7; j++) {
            int idx = i;
            for(int m=0; m<j-i; m++) {
                idx+= 7-m;
            }
            for(int k=0; k<3; k++) {
                board.pile[j][i][k] = deck[idx][k];
            }
        }
    }

    // mark the cards on top of the deck as "open"
    for(int i=0; i<7; i++){
        char* card = board.pile[i][0];
        board.C_OPEN(card);
    }

    // add rest of the cards to "stock"
    for(int i=TOTAL_CARD_NUM-STOCK_SIZE, k=0; i<TOTAL_CARD_NUM; i++, k++) {
        for(int j=0; j<3; j++){
            board.stock[k][j] = deck[i][j];
        }
    }
    return board;
}
