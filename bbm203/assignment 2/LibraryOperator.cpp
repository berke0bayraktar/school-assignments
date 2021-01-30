//
// Created by berke on 26.11.2020.
//

#include "LibraryOperator.h"

void LibraryOperator::ExecuteCommand(LibrarySystem &sys, std::string &method, std::string *params) {
    // <addMovie><tab><movieId><tab><movieTitle><tab><movieYear>
    if (method == "addMovie") {
        int movieId, movieYear;
        std::string movieTitle;

        movieId = std::stoi(params[0]);
        movieYear = std::stoi(params[2]);
        movieTitle = params[1];

        sys.AddMovie(movieId, movieTitle, movieYear);
    }

    // <deleteMovie><tab><movieId>
    else if (method == "deleteMovie") {
        int movieId = std::stoi(params[0]);
        sys.DeleteMovie(movieId);
    }

    // <addUser><tab><userId><tab><userName>
    else if (method == "addUser") {
        int userId = std::stoi(params[0]);
        std::string userName = params[1];
        sys.AddUser(userId, userName);
    }

    // <deleteUser><tab><userId>
    else if (method == "deleteUser") {
        int userId = std::stoi(params[0]);
        sys.DeleteUser(userId);
    }

    // <checkoutMovie><tab><movieId><tab><userId>
    else if (method == "checkoutMovie") {
        int movieId = std::stoi(params[0]);
        int userId = std::stoi(params[1]);
        sys.CheckoutMovie(movieId, userId);
    }

    // <showUser><tab><userId>
    else if (method == "showUser") {
        int userId = std::stoi(params[0]);
        sys.ShowUser(userId);

    }

    // <showMovie><tab><movieId>
    else if (method == "showMovie") {
        int movieId = std::stoi(params[0]);
        sys.ShowMovie(movieId);
    }

    // <showAllMovies>
    else if (method == "showAllMovie") {
        sys.ShowAllMovies();
    }

    // <returnMovie><tab><movieId>
    else if (method == "returnMovie") {
        int movieId = std::stoi(params[0]);
        sys.ReturnMovie(movieId);
    }
}
