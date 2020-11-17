#include "board.h"
#include <string>
#include <vector>
#include "GameController.h"
#include "IO.h"

using namespace std;

int main(int argc, char *argv[]) {

    const char* DECK_PATH = argv[1];
    const char* COMMAND_PATH = argv[2];
    const char* OUTPUT_PATH = argv[3];

    IO io(DECK_PATH, COMMAND_PATH, OUTPUT_PATH);

    //read the deck
    char deck[52][3];
    io.ReadDeck(deck);

    //build the board using the deck
    Board board = BoardBuilder::Build(deck);

    io.Start(&board);

    string methodName;
    int params[3];

    //read & execute commands
    while(io.ReadCommand(methodName, params)) {
        if (methodName == "exit") {
            io.WriteExit();
            break;
        }
        try {
            GameController::ExecuteCommand(&board, methodName, params);
            io.WriteState();
        }
        catch (std::exception& e) {
            io.WriteStateBad();
        }
    }

    if(GameController::WinState(board)) {
        io.WriteWin();
    }
    io.End();
}







