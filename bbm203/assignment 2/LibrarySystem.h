//
// Created by berke on 26.11.2020.
//

#ifndef ASSIGNMENT2_LIBRARYSYSTEM_H
#define ASSIGNMENT2_LIBRARYSYSTEM_H

#include "DoublyCircularLinkedList.h"
#include "SinglyCircularLinkedList.h"

class LibrarySystem {
private:
    DoublyCircularLinkedList users;
    SinglyCircularLinkedList notCheckedOutMovies;
    std::string strRep;

public:
    void AddMovie(int movieId, std::string name, int year);
    void DeleteMovie(int movieId);

    void AddUser(int userId, std::string name);
    void DeleteUser(int userId);

    void CheckoutMovie(int movieId, int userId);
    void ReturnMovie(int movieId);

    void ShowAllMovies();
    void ShowMovie(int movieId);
    void ShowUser(int userId);

    std::string GetStrRep();
};

#endif //ASSIGNMENT2_LIBRARYSYSTEM_H
