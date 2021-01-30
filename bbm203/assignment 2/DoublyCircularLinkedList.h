//
// Created by berke on 25.11.2020.
//

#ifndef ASSIGNMENT2_DOUBLYCIRCULARLINKEDLIST_H
#define ASSIGNMENT2_DOUBLYCIRCULARLINKEDLIST_H

#include <string>
#include "UserNode.h"


class DoublyCircularLinkedList {
private:
    /* since we also have backwards link in doubly linked list
     * we don't need an extra *rear like we do in singly list
     * in order to reduce time complexity */
    UserNode *head = nullptr, *iter = nullptr;

    /* keeping track of number of elements makes it easier to
     * implement the destructor*/
    int size = 0;

    /* for methods that need to return a node such as "FindBy" methods
     * instead of actually returning anything we expect caller to pass in
     * a parameter which will be "filled" by the said node that needs to
     * be returned. This is done in order to save the return type for an int
     * which should tell the caller whether the operation was successful or not
     *
     * the corresponding method for singly linked list class will have a smaller
     * difference such that instead of a double pointer and a single pointer it has
     * a single pointer to be filled and the object itself. We need this type of parameters
     * here because class members are "User" objects and they also hold heap allocated lists on
     * themselves this way we are preventing a shallow copy problem and getting access to
     * the pointer to the object*/
    void fill_in(UserNode** dest, UserNode* src);

public:
    /* nodes are allocated on heap so destructor will free
     * those memory allocations upon object destruction*/
    ~DoublyCircularLinkedList();
    // precondition: Node with same id should not already exist
    void Add(int id, std::string name);
    // precondition: Node with id {id} should be present in list
    void RemoveById(int id);

    /* returns 1 if it could found else returns 0
     * {userNode} will be filled with a pointer to the
     * node we are searching if not interested in value pass nullptr */
    int FindById(int id, UserNode** userNode);

    /* searches all the users for a movie specified by {movieId}
     * returns 1 if it could find the movie on any user else returns 0
     * {userNode} will be filled with a pointer to the node
     * we are searching if not interested in value past nullptr */
    int FindMovieById(int movieId, UserNode** userNode);

    /* iterates over the elements in the list
     * returns 1 as long as there are still elements
     * that have not been iterated through else returns 0
     * {userNode} will be filled with a pointer to the
     * current userNode */
    int Next(UserNode** userNode);
};


#endif //ASSIGNMENT2_DOUBLYCIRCULARLINKEDLIST_H
