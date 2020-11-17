#include "boardprinter.h"

void BoardPrinter::Print(Board* board, std::ofstream& outputFile) {
    /* to be able to print the game we need info about:
     * 1) stock
     * 2) waste slots
     * 3) foundation slots
     * 4) piles
     * */

    //print stock
    bool stockIsEmpty = board->stockSize == 0;
    if (stockIsEmpty) { outputFile << EMPTY; }
    else outputFile << SECRET;

    outputFile << ONE_SPACE;

    //TODO: CHECK FOR EMPTY
    //print waste slots

        //print top of waste array

        if (board->wasteSize == 0) {
            outputFile << EMPTY;
        }
        else {

            for(int i=0; i<3; i++){
                outputFile << board->waste[0][i];
            }
        }

        outputFile << ONE_SPACE;

        //print slot 1
        if(board->C_EMPTY(board->wasteSlot1)) {
           outputFile << EMPTY;
        }
        else {
            for(int i=0; i<3; i++) {
                outputFile << board->wasteSlot1[i];
            }
        }

        outputFile << ONE_SPACE;

        if(board->C_EMPTY(board->wasteSlot2)) {
            outputFile << EMPTY;
        }
        else {
            for(int i=0; i<3; i++) {
                outputFile << board->wasteSlot2[i];
            }
        }

    //space between waste and foundation
    outputFile << NINE_SPACE;

    //print foundation

    for (int i = 0; i < SUIT_TYPE_NUM; i++) {
        if (board->foundation[i][0][0] == '\0') {
            outputFile << EMPTY;
        } else {
            //print the string
            for (int j = 0; j < CARD_REP_SIZE; j++) {
                outputFile << board->foundation[i][0][j];
            }
        }
        outputFile << ONE_SPACE;
    }

    //move down

    outputFile << std::endl;
    outputFile << std::endl;

    //print the piles

    int ptr[7];
    for (int i = 0; i < 7; i++) {
        ptr[i] = DECK_CARD_MAX-1;
    }

    for (int i = 0; i < 7; i++) {
        while (board->pile[i][ptr[i]][0] == '\0') {
            ptr[i]--;
        }
    }

    while (true) {
        //check if all printed
        bool allPrinted = true;
        for (int i = 0; i < 7; i++) {
            if (ptr[i] >= 0) {
                allPrinted = false;
                break;
            }
        }

        if (allPrinted) {
            break;
        }

        for (int i = 0; i < 7; i++) {
            if (ptr[i] >= 0) {
                char* card = board->pile[i][ptr[i]];

                if (board->C_IS_OPEN(card)) {
                    for (int s = 0; s < 3; s++) {
                        outputFile << board->pile[i][ptr[i]][s];
                    }
                } else {
                    outputFile << SECRET;
                }

                ptr[i]--;
            } else {
                outputFile << THREE_SPACE;
            }
            outputFile << THREE_SPACE;
        }
        outputFile << std::endl;
    }
}