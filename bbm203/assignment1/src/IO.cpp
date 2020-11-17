
#include "IO.h"


void IO::ReadDeck(char deck[52][3]) {
    for(int i=51; i>=0; i--){
        for(int s=0; s<3; s++){
            deckFile >> deck[i][s];
        }
    }
    deckFile.close();
}

int IO::ReadCommand(std::string& methodName, int params[3]) {
    std::string command;
    if ((getline(commandFile, command))) {
        int idx = command.find_first_of("0123456789");
        currentCommand = command;
        if (idx == std::string::npos) {
            methodName = command;
        }

        else {
            methodName = command.substr(0,idx-1);
            std::string params_sep = command.substr(idx);
            int counter = 0;
            std::istringstream is(params_sep);
            int n;
            while( is >> n ) {
                params[counter++] = n;
            }
        }
        return 1;
    }
    outputFile << std::endl << std::endl << SEPARATOR << std::endl << std::endl;
    return 0;
}

IO::IO(const char* DECK_FILE_PATH, const char *COMMAND_FILE_PATH, const char *OUTPUT_FILE_PATH) {
    commandFile.open(COMMAND_FILE_PATH);
    outputFile.open(OUTPUT_FILE_PATH);
    deckFile.open(DECK_FILE_PATH);
}

void IO::WriteState() {
    outputFile << std::endl;
    outputFile << currentCommand << std::endl << std::endl;
    outputFile << SEPARATOR << std::endl;
    outputFile << std::endl;
    BoardPrinter::Print(board, outputFile);
}

void IO::WriteStateBad() {
    outputFile << std::endl;
    outputFile << currentCommand << std::endl << std::endl;
    outputFile << "Invalid Move !" << std::endl << std::endl;
    outputFile << SEPARATOR << std::endl;
    outputFile << std::endl;
    BoardPrinter::Print(board, outputFile);
}

void IO::WriteWin() {
    outputFile << "You Win !" << std::endl;
    outputFile << std::endl;
}

void IO::End() {
    outputFile << "Game Over !" << std::endl;
    commandFile.close();
    outputFile.close();
}

void IO::Start(Board *board) {
    this->board = board;
    outputFile << std::endl;
    BoardPrinter::Print(board, outputFile);
}

void IO::WriteExit() {
    outputFile << std::endl;
    outputFile << "exit" << std::endl << std::endl;
    outputFile << SEPARATOR << std::endl << std::endl;
}
