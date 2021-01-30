//
// Created by berke on 26.11.2020.
//

#include "LibrarySystem.h"
#include "LibraryException.h"

void LibrarySystem::AddMovie(int movieId, std::string name, int year) {
    // we first check if the movie already exists
    if (notCheckedOutMovies.FindById(movieId, nullptr) || users.FindMovieById(movieId, nullptr)) { // already exists
        throw LibraryException("movie already exists");
    }

    // if movie with such id is not found we may add to list
    notCheckedOutMovies.Add(movieId, name, year);
}

void LibrarySystem::DeleteMovie(int movieId) {
    strRep.clear();

    UserNode* user;
    // we first check if the movie is not checked out
    if (notCheckedOutMovies.FindById(movieId, nullptr)) { // not checked out
        notCheckedOutMovies.RemoveById(movieId);
        strRep = "not checked out";
    }
    // if it is not in that list we check if any of the users have it
    else if (users.FindMovieById(movieId, &user)) { // one of the users have it
        user->movies.RemoveById(movieId);
        strRep = "was checked out";
    }
    else { // if all of the above is false then no such movie
        throw LibraryException("movie not found");
    }
}

void LibrarySystem::AddUser(int userId, std::string name) {
    // we first check if the user already exists
    if (users.FindById(userId, nullptr)) { // already exists
        throw LibraryException("user already exists");
    }
    users.Add(userId, name);
}

void LibrarySystem::DeleteUser(int userId) {
    // we first check if the user we want to delete is actually present
    if (users.FindById(userId, nullptr)) { // present
        /* we also need to remove every movie the user currently holds from the system completely
         * destructor of "SinglyCircularLinkedList" will do that */
        users.RemoveById(userId);
    }
    else {
        throw LibraryException("user not found");
    }
}

void LibrarySystem::CheckoutMovie(int movieId, int userId) {
    // we first check if the movie that needs to be checked out is absent
    MovieNode movie;
    if (!notCheckedOutMovies.FindById(movieId, &movie)) { // absent
        throw LibraryException("movie not found");
    }

    // we then check if the user that needs to check out the movie is absent
    UserNode* user = nullptr;
    if (!users.FindById(userId, &user)) { // absent
        throw LibraryException("user not found");
    }

    /* if both conditions are satisfied we can move the movie from
     * library storage to user storage*/

    notCheckedOutMovies.RemoveById(movieId);
    user->movies.Add(movie.id, movie.name, movie.year);
}

void LibrarySystem::ReturnMovie(int movieId) {
    // since this is a function to return a movie we first check which user has this movie
    UserNode* userNode;
    if(users.FindMovieById(movieId, &userNode)) {
        // get the movie itself
        MovieNode movie;
        userNode->movies.FindById(movieId, &movie);

        userNode->movies.RemoveById(movieId);

        notCheckedOutMovies.Add(movie.id, movie.name, movie.year);
    }

    else if (notCheckedOutMovies.FindById(movieId, nullptr)) {
        throw LibraryException("movie not checked out");
    }
    else { // the movie doesn't exist at all
        throw LibraryException("movie not found");
    }

}

void LibrarySystem::ShowAllMovies() {
    strRep.clear();

    MovieNode movie;
    UserNode* user;

    // title

    strRep.append("Movie id").append(" - ")
        .append("Movie name").append(" - ")
        .append("Year").append(" - ")
        .append("Status").append("\n");

    // we first traverse the movies that are not checked out
    while(notCheckedOutMovies.Next(&movie)) {
        strRep
            .append(std::to_string(movie.id)).append(" ")
            .append(movie.name).append(" ")
            .append(std::to_string(movie.year)).append(" ")
            .append("Not Checked out").append("\n");
    }

    // we then traverse all the users' movies

    while (users.Next(&user)) {
        //for each user we will look at all the books they have
        while(user->movies.Next(&movie)) {
            strRep
                .append(std::to_string(movie.id)).append(" ")
                .append(movie.name).append(" ")
                .append(std::to_string(movie.year)).append(" ")
                .append("Checked out by User").append(" ")
                .append(std::to_string(user->id)).append("\n");
        }
    }
}

void LibrarySystem::ShowMovie(int movieId) {
    strRep.clear();

    MovieNode movie;
    UserNode* user;

    // first we search it in the movies that are not checked out
    if (notCheckedOutMovies.FindById(movieId, &movie)) { // movie not checked out
        strRep
            .append(std::to_string(movieId)).append(" ")
            .append(movie.name).append(" ")
            .append(std::to_string(movie.year)).append(" ")
            .append(std::to_string(movie.year)).append(" ")
            .append("Not checked out").append("\n");
    }

    // if we couldn't find there we check if one of the users took it
    else if (users.FindMovieById(movieId, &user)) { // someone took it
        // get the movie itself
        user->movies.FindById(movieId, &movie);

        strRep
            .append(std::to_string(movieId)).append(" ")
            .append(movie.name).append(" ")
            .append("Checked out by User").append(" ")
            .append(std::to_string(user->id)).append("\n");
    }
    else { // no such movie
        throw LibraryException("movie not found");
    }
}

void LibrarySystem::ShowUser(int userId) {
    strRep.clear();

    UserNode* user;
    MovieNode movie;

    users.FindById(userId, &user);

    // information about user
    strRep
        .append("User id:").append(" ")
        .append(std::to_string(user->id)).append(" ")
        .append("User name:").append(" ").append(user->name).append("\n");

    /* movies this user currently has (title)
     * this part should not be displayed if there aren't any movies*/
    strRep
        .append("User").append(" ")
        .append(std::to_string(user->id)).append(" ")
        .append("checked out the following Movies:").append("\n")
        .append("Movie id").append(" - ").append("Movie name").append(" - ").append("Year").append("\n");

    bool noMovies = true;

    // movies themselves
    while(user->movies.Next(&movie)) {
        noMovies = false; // if we are inside this loop there must be at least 1 movie
        strRep
            .append(std::to_string(movie.id)).append(" ")
            .append(movie.name).append(" ")
            .append(std::to_string(movie.year)).append(" ").append("\n");
    }

    if (noMovies) {
        strRep.clear();
        strRep
                .append("User id:").append(" ")
                .append(std::to_string(user->id)).append(" ")
                .append("User name:").append(" ").append(user->name).append("\n");
        strRep
                .append("User").append(" ")
                .append(std::to_string(user->id)).append(" ")
                .append("checked out the following Movies:").append("\n");
    }
}

std::string LibrarySystem::GetStrRep() {
    std::string returnValue = this->strRep;
    this->strRep.clear();
    return returnValue;
}
