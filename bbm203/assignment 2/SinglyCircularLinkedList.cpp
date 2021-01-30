//
// Created by berke on 25.11.2020.
//

#include "SinglyCircularLinkedList.h"


// we insert elements into linked list as if it were a stack
void SinglyCircularLinkedList::Add(int id, std::string name, int year) {
    MovieNode* temp = new MovieNode(id, name, year);
    if (head == nullptr && rear == nullptr) { // list is empty
        head = temp; rear = temp;
        temp->next = temp;
    }
    else {
        rear->next = temp;
        temp->next = head;
        head = temp;
    }
    size++;
}

void SinglyCircularLinkedList::RemoveById(int id) {
    if (head == rear) { // list contains only one element
        delete head;
        head = nullptr; rear = nullptr; size--;
        return;
    }

    // if there are more elements we want to find the element with the correct id
    MovieNode* temp = head;

    while(temp->next->id != id) {
        temp = temp->next;
    }
    // after we are done with the loop temp now points to node BEFORE the node we want to remove
    MovieNode* nodeBefore = temp;

    // since there are more than 1 elements it is guaranteed that this value will not be null
    MovieNode* nodeToRemove = temp->next;

    /* there are 2 edge cases when removing a node from singly circular linked list
     * 1 - node we want to remove is head node
     * 2 - node we want to remove is rear node*/

    if (nodeToRemove == head) {
        nodeBefore->next = nodeToRemove->next;
        head = nodeToRemove->next;
        delete nodeToRemove;
    }
    else if (nodeToRemove == rear) {
        nodeBefore->next = nodeToRemove->next;
        rear = nodeBefore;
        delete nodeToRemove;
    }
    else {
        nodeBefore->next = nodeToRemove->next;
        delete nodeToRemove;
    }
    size--;
}

int SinglyCircularLinkedList::FindById(int id, MovieNode* movieNode) {
    if (head == nullptr && rear == nullptr) { // list is empty
        return 0;
    }
    if (head == rear) { // list contains only one element
        fill_in(movieNode, head);
        return head->id == id;
    }

    // if there are more than one elements we want to search the whole list
    MovieNode* temp = head;

    while(temp->id != id) {
        temp = temp->next;
        if (temp == head) { // temp was initially {head} if it is again head than we have traversed all the list
            return 0;
        }
    }
    // if we can exit from the while loop then we have found the item and temp is currently pointing at it
    fill_in(movieNode, temp);
    return 1;
}

SinglyCircularLinkedList::~SinglyCircularLinkedList() {
    // before destroying the list we will remove all of its dynamically allocated elements
    MovieNode* temp = head;
    for(int i=0; i<size; i++) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

int SinglyCircularLinkedList::Next(MovieNode *movieNode) {
    if (head == nullptr) {
        return 0;
    }

    if (iter == nullptr) {
        iter = head;
        *movieNode = *head;
        return 1;
    }

    iter = iter->next;

    if (iter == head) { // we have traversed all the list
        iter = nullptr;
        return 0;
    }
    else {
        *movieNode = *iter;
        return 1;
    }
}

void SinglyCircularLinkedList::fill_in(MovieNode *dest, MovieNode *src) {
    if (dest != nullptr) {
        *dest = *src;
    }
}
