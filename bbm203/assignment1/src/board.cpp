#include "board.h"
#include <iostream>
#include <cstring>

Board::Board() : open(), pile(), foundation(), stock(), waste(), wasteSlot1(), wasteSlot2() {}

/*PUBLIC METHOD IMPL*/

void Board::OpenFromStock() {
    /*Edge cases:
     * 1) stock is empty, waste cards should be transferred back to stock
     * 2) stock size is less than 3*/


    //check for edge case #1
    if(stockSize == 0) {
        REFILL();
        return;
    }

    //If waste slots are nonempty carry them to waste array
    if (!C_EMPTY(wasteSlot1)) {
        SLOT_TO_WASTE(wasteSlot1);
    }
    if (!C_EMPTY(wasteSlot2)) {
        SLOT_TO_WASTE(wasteSlot2);
    }

    //carry the first element from stock to waste array, second to wasteSlot1 third to wasteSlot2

    //edge case check above should handle
    if (stockSize == 1) {
        STOCK_TO_WASTE(1);
    }
    else if (stockSize == 2) {
        STOCK_TO_WASTE(1);
        STOCK_TO_SLOT(wasteSlot1);
    }
    else {
        STOCK_TO_WASTE(1);
        STOCK_TO_SLOT(wasteSlot1);
        STOCK_TO_SLOT(wasteSlot2);
    }



}
void Board::MoveToFoundationFromPile(int pileIdx) {
    char* incomingCard = pile[pileIdx][0];

    //decide which foundation
    char suit = C_SUIT(incomingCard);
    int fndIdx = SUIT_TO_IDX(suit);

    //check if it obeys rule
    if(C_PRED_FND(incomingCard, fndIdx)) {
        PILE_TO_FND(pileIdx, fndIdx);
    } else {
        throw std::exception();
    }
}


void Board::MovePile(int pileSrc, int idx, int pileDest) {
    char* incomingCard = pile[pileSrc][idx];
    char* presentCard = pile[pileDest][0];

    //check if it obeys rule
    if(C_PRED(incomingCard, presentCard)) {
        PILE_TO_PILE(pileSrc, pileDest, idx+1);
    } else {
        throw std::exception();
    }

}
void Board::MoveWaste(int pileDest) {
    char* incomingCard;
    char* presentCard = pile[pileDest][0];

    //decide which waste
    if(!C_EMPTY(wasteSlot2)) {
        incomingCard = wasteSlot2;
    }
    else if (!C_EMPTY(wasteSlot1)) {
        incomingCard = wasteSlot1;
    }
    else {
        WASTE_TO_SLOT(wasteSlot1);
        incomingCard = wasteSlot1;
    }



    //check rule
    if(C_PRED(incomingCard, presentCard)){
        C_OPEN(incomingCard);
        SLOT_TO_PILE(incomingCard, pileDest);
    } else {
        throw std::exception();
    }
}
void Board::MoveFoundation(int srcFoundation, int pileDest) {
    char* incomingCard = foundation[srcFoundation][0];
    char* presentCard = pile[pileDest][0];

    //check rule
    if (C_PRED(incomingCard, presentCard)) {
        FND_TO_PILE(srcFoundation, pileDest);
    } else {
        throw std::exception();
    }
}

void Board::Open(int pileIdx) {
    const char* card = pile[pileIdx][0];
    if (C_IS_OPEN(card)) {
        throw std::exception();
    }
    else {
        C_OPEN(card);
    }
}


/*PRIVATE METHOD IMPL*/

void Board::C_MOVE(void *from, void *to, int cardCount) {
    memcpy(to, from, CARD_REP_SIZE*cardCount);
}

int Board::C_PRED(const char *card1, const char *card2) {
    if (C_EMPTY(card1)) {
        return C_VAL(card2) == 1;
    }
    else if (C_EMPTY(card2)) {
        return C_VAL(card1) == 13;
    }

    //check if suites match
    char c1Suit = C_SUIT(card1);
    char c2Suit = C_SUIT(card2);

    bool colorMatch = (((c1Suit == 'D' || c1Suit == 'H') &&
                        (c2Suit == 'S' || c2Suit == 'C')) ||
                       ((c1Suit == 'S' || c1Suit == 'C') &&
                        (c2Suit == 'D' || c2Suit == 'H')));

    //check if values match
    int c1Val = C_VAL(card1);
    int c2Val = C_VAL(card2);
    bool valueMatch = c1Val+1 == c2Val;

    return colorMatch && valueMatch;


}

int Board::C_PRED_FND(const char *card, int fndIdx) {
    char* cardAtFoundation = foundation[fndIdx][0];
    if (C_EMPTY(cardAtFoundation) && C_VAL(card) == 1) {
        return 1;
    }

    char incomingCardSuit = C_SUIT(card);
    int incomingCardValue = C_VAL(card);

    char presentCardSuit = C_SUIT(cardAtFoundation);
    int presentCardValue = C_VAL(cardAtFoundation);

    bool matchingSuit = incomingCardSuit == presentCardSuit;
    bool matchingValue = presentCardValue+1 == incomingCardValue;
    return matchingSuit && matchingValue;

}

char Board::C_SUIT(const char *card) {
    return *card;
}

 int Board::C_VAL(const char* card) {
    return atoi(card+1);
}

int Board::C_IS_OPEN(const char *card) {
    char suit = *card;
    int value = atoi(card+1);
    return open[SUIT_TO_IDX(suit)][value-1];
}

void Board::C_OPEN(const char *card) {
    char suit = *card;
     int value = atoi(card+1);
    open[SUIT_TO_IDX(suit)][value-1] = 1;
}

int Board::C_EMPTY(const char *card) {
    return *card == '\0';
}

int Board::SUIT_TO_IDX(char suit) {
    switch (suit) {
        case 'H': return 0;
        case 'D': return 1;
        case 'S': return 2;
        case 'C': return 3;
    }
	return 0;
}

void Board::STOCK_TO_WASTE(int count) {

    //make space for incoming cards on waste
    C_MOVE(waste, waste+count, wasteSize);

    //mark spaces as empty
    C_MARK_EMPTY(waste, count);

    //move from stock to waste

    C_MOVE(stock, waste, count);

    //move stock back
    C_MOVE(stock+count, stock, stockSize);

    //mark slots at back as empty
    C_MARK_EMPTY(stock+stockSize-count, count);

    //update sizes
    stockSize-=count;
    wasteSize+=count;
}

void Board::PILE_TO_FND(int src, int fndIdx) {

    //make space for incoming cards on foundation
    C_MOVE(foundation[fndIdx], foundation[fndIdx]+1, foundationSizes[fndIdx]*1);

    //mark open space as empty
    C_MARK_EMPTY(foundation[fndIdx], 1);

    //move the card from pile to foundation
    C_MOVE(pile[src], foundation[fndIdx], 1);

    //move cards to front in pile
    C_MOVE(pile[src]+1, pile[src], pileSizes[src]*1);

    //mark slots on back of pile empty
    C_MARK_EMPTY(pile[src]+pileSizes[src]-1, 1);

    //update sizes
    pileSizes[src]--;
    foundationSizes[fndIdx]++;

}

void Board::SLOT_TO_FND(char* slot, int fndIdx) {

    //make space for incoming card on foundation
    C_MOVE(foundation[fndIdx], foundation[fndIdx]+1, foundationSizes[fndIdx]);

    //mark space as empty
    C_MARK_EMPTY(foundation[fndIdx], 1);

    //copy from slot to foundation
    C_MOVE(slot, foundation[fndIdx], 1);

    //mark slot as empty
    C_MARK_EMPTY(slot, 1);
    foundationSizes[fndIdx]++;
}

void Board::PILE_TO_PILE(int src, int dest, int count) {
    //make space for incoming cards on destination pile
    C_MOVE(pile[dest], pile[dest]+count, pileSizes[dest]);

    //mark open space as empty
    C_MARK_EMPTY(pile[dest], count);

    //move the cards from source to destination
    C_MOVE(pile[src], pile[dest], count);

    //move cards front in source
    C_MOVE(pile[src]+count, pile[src], pileSizes[src]);

    //mark slots at back as empty
    C_MARK_EMPTY(pile[src]+pileSizes[src]-count, count);

    //update sizes
    pileSizes[src] -= count;
    pileSizes[dest] += count;

}

void Board::SLOT_TO_PILE(char* slot, int dest) {

    //make space for incoming card on pile
    C_MOVE(pile[dest], pile[dest]+1, pileSizes[dest]);

    //mark space as empty
    C_MARK_EMPTY(pile[dest], 1);

    //move the card from waste to destination pile
    C_MOVE(slot, pile[dest], 1);

    //mark slot empty
    C_MARK_EMPTY(slot, 1);

    pileSizes[dest]++;

}

void Board::FND_TO_PILE(int fndIdx, int dest) {
    //make space for incoming card on destination pile
    C_MOVE(pile[dest], pile[dest]+1, pileSizes[dest]);

    //mark space as empty
    C_MARK_EMPTY(pile[dest], 1);

    //copy the card from foundation to pile
    C_MOVE(foundation[fndIdx], pile[dest], 1);

    //move the cards front in foundation
    C_MOVE(foundation[fndIdx]+1, foundation[fndIdx], foundationSizes[fndIdx]);

    //mark slots at back as empty
    C_MARK_EMPTY(foundation[fndIdx]+foundationSizes[fndIdx]-1,1);

    //update sizes
    foundationSizes[fndIdx]--;
    pileSizes[dest]++;

}

void Board::C_MARK_EMPTY(void *ptr, int cardCount) {
    memset(ptr, 0, CARD_REP_SIZE*cardCount);
}

void Board::REFILL() {

    if(!C_EMPTY(wasteSlot1)) {
        SLOT_TO_WASTE(wasteSlot1);
    }

    if(!C_EMPTY(wasteSlot2)) {
        SLOT_TO_WASTE(wasteSlot2);
    }


    for(int i=wasteSize-1,k=0; i>=0; i--,k++) {
        memcpy(stock+k, waste+i, CARD_REP_SIZE);
    }

    C_MARK_EMPTY(waste, wasteSize);

    stockSize = wasteSize;
    wasteSize = 0;

}
void Board::SLOT_TO_WASTE(char* slot) {
    C_MOVE(waste, waste+1, wasteSize);

    //mark space as empty
    C_MARK_EMPTY(waste, 1);

    //copy from slot to waste
    C_MOVE(slot, waste, 1);

    //mark slot as empty
    C_MARK_EMPTY(slot, 1);

    wasteSize++;
}

void Board::STOCK_TO_SLOT(char* slot) {
    //copy from stock to slot
    C_MOVE(stock, slot, 1);

    //move stock front
    C_MOVE(stock+1, stock, stockSize);

    //mark back of stock empty
    C_MARK_EMPTY(stock+stockSize-1, 1);
    stockSize--;
}

void Board::WASTE_TO_SLOT(char *slot) {
    //move from waste to slot
    C_MOVE(waste, slot, 1);

    //move waste front
    C_MOVE(waste+1, waste, wasteSize);

    //mark back as empty
    C_MARK_EMPTY(waste+wasteSize-1, 1);
    wasteSize--;
}

void Board::WASTE_TO_FND(int fndIdx) {

    //make space for incoming card on foundation
    C_MOVE(foundation[fndIdx], foundation[fndIdx]+1, foundationSizes[fndIdx]);

    //mark space as empty
    C_MARK_EMPTY(foundation[fndIdx], 1);

    //copy from waste to foundation
    C_MOVE(waste[0], foundation[fndIdx], 1);

    //mark slot as empty
    C_MARK_EMPTY(waste, 1);

    //update sizes
    foundationSizes[fndIdx]++;
    wasteSize--;
}

void Board::MoveToFoundationFromWaste() {
    char* incomingCard;
    bool comingFromWaste = false;
    //decide which waste slot
    if(!C_EMPTY(wasteSlot2)) {
        incomingCard = wasteSlot2;
    }
    else if (!C_EMPTY(wasteSlot1)) {
        incomingCard = wasteSlot1;
    }
    else {
        incomingCard = waste[0];
        comingFromWaste = true;
    }

    //decide which foundation
    char suit = C_SUIT(incomingCard);
    int fndIdx = SUIT_TO_IDX(suit);

    //check if it obeys rule
    if(C_PRED_FND(incomingCard, fndIdx)) {
        if(comingFromWaste) {
            WASTE_TO_FND(fndIdx);
        }
        else {
            SLOT_TO_FND(incomingCard, fndIdx);
        }
    } else {
        throw std::exception();
    }
}

int Board::WinState() {
    //all foundations should have 13 on top

    for(int i=0; i<4; i++) {
        const char* cardAtTopOfFoundation = foundation[i][0];
        if (C_VAL(cardAtTopOfFoundation) != 13) {
            return 0;
        }
    }
    return 1;
}
