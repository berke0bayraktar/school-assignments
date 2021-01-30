//
// Created by berke on 26.11.2020.
//

#ifndef ASSIGNMENT2_LIBRARYIO_H
#define ASSIGNMENT2_LIBRARYIO_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <set>
#include "LibraryException.h"

#define LIBRARY_HEADER "===Movie Library System==="

class LibraryIO {
private:
    std::ifstream commandFile;
    std::ofstream outputFile;
    std::string COMMANDS_PATH, OUTPUT_PATH;

    std::string lastExecutedMethodName;

    void split_string(std::string strParams, std::string params[]);
    void print_header_if_not_printed(std::string methodName);

    void add_movie_success(std::string movieId);
    void add_movie_fail(std::string movieId);

    void delete_movie_success(std::string movieId, std::string& strRep);
    void delete_movie_fail(std::string movieId);

    void add_user_success(std::string userId);
    void add_user_fail(std::string userId);

    void delete_user_success(std::string userId);
    void delete_user_fail(std::string userId);

    void checkout_movie_success(std::string movieId, std::string userId);
    void checkout_movie_fail(std::string movieId, std::string userId, LibraryException e);

    void show_user_success(std::string& strRep);
    void show_user_fail(std::string userId);

    void return_movie_success(std::string movieId);
    void return_movie_fail(std::string movieId, LibraryException e);

    void show_movie_success(std::string& strRep);
    void show_movie_fail(std::string movieId);

    //this method will not have a failure situation
    void show_all_movies_success(std::string& strRep);

public:
    LibraryIO(std::string commandsPath, std::string outputsPath);

    // open all necessary files
    void Start();

    // close all opened files
    void End();

    /* this function will not convert numerical parameters into integers
     * it leaves them as strings the caller should make the conversion*/
    int GetCommand(std::string* method, std::string params[]);

    // handles io situations which the operation was successfully carried
    void Success(std::string method, std::string params[], std::string& strRep);

    // handles io situations which the operation could not be carried
    void Fail(std::string method, std::string params[], std::string& strRep, LibraryException e);
};
#endif //ASSIGNMENT2_LIBRARYIO_H
