//
// Created by berke on 26.11.2020.
//

#include "LibraryIO.h"

void LibraryIO::split_string(std::string strParams, std::string *params) {
    std::stringstream ss(strParams);
    std::string param;
    int i=0;
    while(getline(ss, param, '\t')) {
        params[i++] = param;
    }
}

LibraryIO::LibraryIO(std::string commandsPath, std::string outputsPath) : COMMANDS_PATH(commandsPath), OUTPUT_PATH(outputsPath) { }

void LibraryIO::Start() {
    commandFile.open(COMMANDS_PATH);
    outputFile.open(OUTPUT_PATH);
    outputFile << LIBRARY_HEADER << std::endl;
}

void LibraryIO::End() {
    commandFile.close();
    outputFile.close();
}

int LibraryIO::GetCommand(std::string *method, std::string *params) {
    std::string line;
    if (getline(commandFile, line)) {
        if (line.find('\t') != std::string::npos) {
            int idx = line.find('\t');
            *method = line.substr(0, idx);
            std::string paramsStr = line.substr(idx+1);
            split_string(paramsStr, params);
        }
        else {
            *method = line;
        }
        return 1;
    }
    return 0;
}

// SUCCESS ROUTER METHOD
void LibraryIO::Success(std::string method, std::string *params, std::string& strRep) {

    print_header_if_not_printed(method);

    // <addMovie><tab><movieId><tab><movieTitle><tab><movieYear>
    if (method == "addMovie") {
        add_movie_success(params[0]);
    }

    // <deleteMovie><tab><movieId>
    else if (method == "deleteMovie") {
        delete_movie_success(params[0], strRep);
    }

    // <addUser><tab><userId><tab><userName>
    else if (method == "addUser") {
        add_user_success(params[0]);
    }

    // <deleteUser><tab><userId>
    else if (method == "deleteUser") {
        delete_user_success(params[0]);
    }

    // <checkoutMovie><tab><movieId><tab><userId>
    else if (method == "checkoutMovie") {
        checkout_movie_success(params[0], params[1]);
    }

    // <showUser><tab><userId>
    else if (method == "showUser") {
        show_user_success(strRep);

    }

    // <showMovie><tab><movieId>
    else if (method == "showMovie") {
        show_movie_success(strRep);
    }

    // <returnMovie><tab><movieId>
    else if (method == "returnMovie") {
        return_movie_success(params[0]);
    }

    // <showAllMovie>
    else if (method == "showAllMovie") {
        show_all_movies_success(strRep);
    }
}

// FAILURE ROUTER METHOD
void LibraryIO::Fail(std::string method, std::string *params, std::string& strRep, LibraryException e) {

    print_header_if_not_printed(method);

    if (method == "addMovie") {
        add_movie_fail(params[0]);
    }

    else if (method == "deleteMovie") {
        delete_movie_fail(params[0]);
    }

    else if (method == "addUser") {
        add_user_fail(params[0]);
    }

    else if (method == "deleteUser") {
        delete_user_fail(params[0]);
    }

    else if (method == "checkoutMovie") {
        checkout_movie_fail(params[0], params[1], e);
    }

    else if (method == "showUser") {
        show_user_fail(params[0]);

    }

    else if (method == "showMovie") {
        show_movie_fail(params[0]);
    }

    else if (method == "returnMovie") {
        return_movie_fail(params[0], e);
    }
}


// ADD MOVIE
void LibraryIO::add_movie_success(std::string movieId) {
    outputFile << "Movie " << movieId << " has been added" << std::endl;
}

void LibraryIO::add_movie_fail(std::string movieId) {
    outputFile << "Movie " << movieId << " already exists" << std::endl;
}

// DELETE MOVIE

/* when we consider all the operations on library
 * all of them are either successfully completed
 * or failed with few possible causes. In such
 * situations the message conveyed by the exception
 * will tell us the root cause of the problem
 *
 * How ever this is not true for delete movie
 * It can be completed successfully in two different ways
 * to handle this unique situation we used the {strRep}
 * parameter to convey the message about success of the operation*/

void LibraryIO::delete_movie_success(std::string movieId, std::string &strRep) {
    if (strRep == "not checked out") {
        outputFile << "Movie " << movieId << " has not been checked out" << std::endl;
        outputFile << "Movie " << movieId << " has been deleted" << std::endl;
    }
    else {
        outputFile << "Movie " << movieId  << " has been checked out" << std::endl;
        outputFile << "Movie " << movieId << " has been deleted" << std::endl;
    }

}

void LibraryIO::delete_movie_fail(std::string movieId) {
    outputFile << "Movie " << movieId << " does not exist" << std::endl;
}



// ADD USER
void LibraryIO::add_user_success(std::string userId) {
    outputFile << "User " << userId << " has been added" << std::endl;
}

void LibraryIO::add_user_fail(std::string userId) {
    outputFile << "User " << userId << " already exists" << std::endl;
}


// DELETE USER
void LibraryIO::delete_user_success(std::string userId) {
    outputFile << "User " << userId << " has been deleted" << std::endl;
}

void LibraryIO::delete_user_fail(std::string userId) {
    outputFile << "User " << userId << " does not exist" << std::endl;
}

// CHECKOUT MOVIE

void LibraryIO::checkout_movie_success(std::string movieId, std::string userId) {
    outputFile << "Movie " << movieId << " has been checked out by User " << userId << std::endl;
}

void LibraryIO::checkout_movie_fail(std::string movieId, std::string userId, LibraryException e) {
    /* checking out a movie can fail in 2 ways
     * 1 - the user is not found
     * 2 - the movie is not found
     * */


    // check what is the actual cause of the exception
    if (e.Message() == "user not found") { // user was not found
        outputFile << "User " << userId << " does not exist for checkout" << std::endl;
    }
    else if (e.Message() == "movie not found") { // movie was already checked out
        outputFile << "Movie " << movieId << " does not exist for checkout" << std::endl;
    }
}

// SHOW USER

void LibraryIO::show_user_success(std::string &strRep) {
    outputFile << strRep;
}

void LibraryIO::show_user_fail(std::string userId) {
    outputFile << "User " << userId << " does not exist" << std::endl;
}

void LibraryIO::return_movie_success(std::string movieId) {
    outputFile << "Movie " << movieId << " has been returned" << std::endl;
}

void LibraryIO::return_movie_fail(std::string movieId, LibraryException e) {
    /* returning a movie can fail in 2 ways
     * 1 - movie was not checked out in the first place
     * 2 - no such movie*/

    // check what is the actual cause
    if (e.Message() == "movie not checked out") {
        outputFile << "Movie " << movieId << " has not been checked out" << std::endl;
    }
    if (e.Message() == "movie not found") {
        outputFile << "Movie " << movieId << " not exists in the library" << std::endl;
    }
}

// SHOW MOVIE

void LibraryIO::show_movie_success(std::string &strRep) {
    outputFile << strRep;
}

void LibraryIO::show_movie_fail(std::string movieId) {
    outputFile << "Movie with the id " << movieId << " does not exist" << std::endl;
}

void LibraryIO::show_all_movies_success(std::string &strRep) {
    outputFile << strRep;
}

void LibraryIO::print_header_if_not_printed(std::string methodName) {
    if (methodName != lastExecutedMethodName) { // we have not printed this header yet
        outputFile << std::endl;
        outputFile << "==" << methodName << "()" << " method test==" << std::endl;
        lastExecutedMethodName = methodName;
    }
}





