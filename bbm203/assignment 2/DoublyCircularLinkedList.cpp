//
// Created by berke on 25.11.2020.
//

#include "DoublyCircularLinkedList.h"

// we insert elements as if it was a stack
void DoublyCircularLinkedList::Add(int id, std::string name) {
    size++;
    UserNode* temp = new UserNode(id, name);

    if (head == nullptr) {
        head = temp;
        temp->next = temp;
        temp->prev = temp;
    }
    else {
        UserNode* rear = head->prev;
        rear->next = temp;
        head->prev = temp;
        temp->next = head;
        temp->prev = rear;
        head = temp;
    }
}

void DoublyCircularLinkedList::RemoveById(int id) {
    size--;

    if (head->next == head) { // list contains only one element
        delete head;
        head = nullptr;
        return;
    }

    // if there are more than 1 elements than we want to find the right node
    UserNode* temp = head;

    while (temp->next->id != id) {
        temp = temp->next;
    }
    // after we are done with the loop temp now points to node BEFORE the node we want to remove
    UserNode* nodeBefore = temp;

    // since there are more than 1 elements it is guaranteed that this value will not be null
    UserNode* nodeToRemove = temp->next;

    UserNode* nodeAfter = nodeToRemove->next;

    /* there is 1 edge case when removing a node from doubly circular linked list
     * 1 - we are trying to remove the head node */

    if (nodeToRemove == head) {
        nodeBefore->next = nodeAfter;
        nodeAfter->prev = nodeBefore;
        delete nodeToRemove;
        head = nodeAfter;
    }
    else {
        nodeBefore->next = nodeAfter;
        nodeAfter->prev = nodeBefore;
        delete nodeToRemove;
    }
}

int DoublyCircularLinkedList::FindById(int id, UserNode **userNode) {
    if (head == nullptr) { // list is empty
        return 0;
    }
    else if (head->next == head) { // list contains only one element
        // only modify the user node if it is wanted (not null)
        fill_in(userNode, head);
        return head->id == id;
    }

    // if there are more than one elements we want to search the whole list
    UserNode* temp = head;

    while(temp->id != id) {
        temp = temp->next;
        if (temp == head) { // temp was initially {head} if it is again head than we have traversed all the list
            return 0;
        }
    }
    // if we can exit from the while loop then we have found the item and temp is currently pointing at it
    fill_in(userNode, temp);
    return 1;

}

int DoublyCircularLinkedList::FindMovieById(int movieId, UserNode **userNode) {
    if (head == nullptr) {
        return 0;
    }
    if (head->prev == head->next) { // only one user
        if (head->next->movies.FindById(movieId, nullptr)) {
            fill_in(userNode, head->next);
            return 1;
        }
        return 0;
    }

    // check the head node explicitly

    if (head->movies.FindById(movieId, nullptr)) {
        fill_in(userNode, head);
        return 1;
    }

    UserNode* temp = head->next;

    while (temp != head) {
        if (temp->movies.FindById(movieId, nullptr)) {
            fill_in(userNode, temp);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int DoublyCircularLinkedList::Next(UserNode **userNode) {
    if (head == nullptr) {
        return 0;
    }

    if (iter == nullptr) {
        iter = head;
        *userNode = iter;
        return 1;
    }

    iter = iter->next;

    if (iter == head) { // we have traversed all the list
        iter = nullptr;
        return 0;
    }
    else {
        *userNode = iter;
        return 1;
    }
}

void DoublyCircularLinkedList::fill_in(UserNode **dest, UserNode *src) {
    if (dest != nullptr) {
        *dest = src;
    }
}

DoublyCircularLinkedList::~DoublyCircularLinkedList() {
    UserNode* temp = head;
    for(int i=0; i<size; i++) {
        head = head->next;
        delete temp;
        temp = head;
    }
}
