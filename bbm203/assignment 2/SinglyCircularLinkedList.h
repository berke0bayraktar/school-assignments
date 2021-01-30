//
// Created by berke on 25.11.2020.
//

#ifndef ASSIGNMENT2_SINGLYCIRCULARLINKEDLIST_H
#define ASSIGNMENT2_SINGLYCIRCULARLINKEDLIST_H

#include <string>
#include "MovieNode.h"

class SinglyCircularLinkedList {
private:
    /*the purpose of keeping a rear node in a singly linked list
     * is to reduce time complexity for Add() operation from O(n) to O(1)
     * since new elements are inserted right before head and head is carried back
     * (like a stack) each time we want to add a new element we would have to
     * traverse the whole list from head to rear because we dont have prev links */
    MovieNode *head = nullptr, *rear = nullptr, *iter = nullptr;
    int size = 0;

    /* the purpose of this function is similar to one in doubly linked list
     * however we don't have a double pointer the reason for that is
     * unlike doubly linked list where we provide a pointer to the item
     * this function provides the item itself. The object is shallow copied
     * and this is not a problem since it doesn't hold any dynamic class members*/
    void fill_in(MovieNode* dest, MovieNode* src);

public:
    ~SinglyCircularLinkedList();
    // precondition: A node with {id} should not already exist
    void Add(int id, std::string name, int year);
    // precondition: Node with {id} should exist
    void RemoveById(int id);

    /* returns 1 if found else returns 0
     * {movieNode} will be filled with the item we are searching
     if not interested in value it self just pass nullptr*/
    int FindById(int id, MovieNode* movieNode);

    int Next(MovieNode* movieNode);
};

#endif //ASSIGNMENT2_SINGLYCIRCULARLINKEDLIST_H
