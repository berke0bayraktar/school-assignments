#ifndef EXP1_IO_H
#define EXP1_IO_H

#include <fstream>
#include "IO.h"
#include <string>
#include <sstream>
#include "boardprinter.h"
#include "board.h"
#include "GameController.h"

#define SEPARATOR "****************************************"

class IO {
private:
    std::ifstream commandFile;
    std::ifstream deckFile;
    std::ofstream outputFile;
    std::string currentCommand;
    Board* board;
public:

    IO(const char* DECK_FILE_PATH, const char* COMMAND_FILE_PATH, const char* OUTPUT_FILE_PATH);

    void ReadDeck(char deck[52][3]);
    int ReadCommand(std::string& methodName, int params[3]);
    void WriteState();
    void WriteStateBad();

    void WriteWin();
    void WriteExit();
    void Start(Board* board);
    void End();
};

#endif
