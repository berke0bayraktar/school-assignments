//
// Created by berke on 7.12.2020.
//

#ifndef ASSIGNMENT3_LIST_H
#define ASSIGNMENT3_LIST_H

#include "ListException.h"


template<typename T>
class List {
public:
    List() {
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }
    ~List() {
        ListNode* temp = _head;
        while (_head != nullptr) {
            _head = _head->next;
            delete temp;
            temp = _head;
        }
    }
    bool isEmpty() const {
        return size() == 0;
    }
    int size() const {
        return _size;
    }
    void append(const T& newItem) {
        ListNode* newNode = new ListNode;
        newNode->item = newItem;

        if (isEmpty()) {
            _head = newNode;
            _tail = newNode;

            _head->next = _tail;
            _tail->prev = _head;
        }
        else {
            _tail->next = newNode;
            newNode->prev = _tail;
            _tail = newNode;
        }
        _size++;
    }
    void remove(int index) {
        if (isEmpty()) {
            throw ListException("list::remove");
        }
        else {

            if (index == 0) {
                if (size() == 1) {
                    delete _head;
                    _head = nullptr;
                    _tail = nullptr;
                }
                else {
                    ListNode* next = _head->next;
                    next->prev = nullptr;
                    delete _head;
                    _head = next;
                }
                _size--;
                return;
            }

            ListNode* temp = _head;
            for(int i=0; i<index-1; i++) {
                temp = temp->next;
            }
            // now, temp is pointing to node before the one we want to remove

            ListNode* prevNode = temp;
            ListNode* nodeToRemove = temp->next;
            ListNode* nextNode = nodeToRemove->next;

            // if we are removing the last node "nextNode" could be NULL

            if (nextNode != nullptr) {
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
            }
            else {
                prevNode->next = nullptr;
                _tail = prevNode;
            }
            delete nodeToRemove;
            _size--;
        }
    }
    void at(int index, T* item) {
        ListNode* temp = _head;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        *item = temp->item;
    }

private:
    struct ListNode {
        T item;
        ListNode *next = nullptr;
        ListNode* prev = nullptr;
    };
    int _size;
    /* to avoid the traversal to the last node,
     an additional pointer to the last node is defined*/
    ListNode *_head;
    ListNode *_tail;
};

#endif //ASSIGNMENT3_LIST_H
