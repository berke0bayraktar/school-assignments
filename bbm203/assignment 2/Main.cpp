#include "SinglyCircularLinkedList.h"
#include "DoublyCircularLinkedList.h"
#include "LibraryIO.h"
#include "LibrarySystem.h"
#include "LibraryOperator.h"

/* !!! IMPORTANT !!!
 * commands used to compile and run this project is
 *  dos2unix commands.txt
 *  dos2unix output.txt (it is not needed if you allow program to create the file from scratch)
 *  g++ -std=c++11 *.cpp -o program
 *  ./program commands.txt output.txt
 * */

int main(int argc, char *argv[]) {
    const char* COMMAND_PATH = argv[1];
    const char* OUTPUT_PATH = argv[2];

    LibraryIO io(COMMAND_PATH, OUTPUT_PATH);
    io.Start();

    LibrarySystem sys;

    /* for operations that have complex outputs we have to
     * retrieve info from the LibrarySystem object. Simply
     * knowing whether the operation was successful or not
     * is not enough for example "showAllMovie" operation.
     * In such cases the output is constructed by the
     * LibrarySystem and passed to LibraryIO via this "strRep" */
    std::string strRep;

    std::string method, params[3];
    while (io.GetCommand(&method, params)) {
        try {
            LibraryOperator::ExecuteCommand(sys, method, params);
            strRep = sys.GetStrRep();
            io.Success(method, params, strRep);
        }
        catch (LibraryException& e) {
            strRep = sys.GetStrRep();
            io.Fail(method, params, strRep, e);
        }
        catch (std::exception& e) {
            std::cout << e.what();
        }
    }
    io.End();
}
