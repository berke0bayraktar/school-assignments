#ifndef ASSIGNMENT3_STACK_H
#define ASSIGNMENT3_STACK_H


/*Function templates are special functions that can operate
with generic types. This allows us to create a function 
template whose functionality can be adapted to more than 
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);

*/

#include "StackException.h"

template <typename T>
class Stack {
	public:
	Stack() {
        _head = nullptr;
        _size = 0;
    }
	~Stack() {
        ListNode* temp = _head;
        while(_head != nullptr) {
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
	
	//Push: Place item on top of the stack
	void push(const T& newItem) {
        ListNode* newNode = new ListNode;
        newNode->item = newItem;

        if (_head == nullptr) {
            _head = newNode;
        }
        else {
            newNode->next = _head;
            _head = newNode;
        }
        _size++;
    }
	//Top: Take a look at the topmost item without removing it
	void getTop(T& stackTop) const {
        if (isEmpty()) {
            throw StackException("stack::getTop");

        }
        else {
            stackTop = _head->item;
        }
    }
	//Pop: Remove item from the top of the stack
	void pop() {
        if (isEmpty()) {
            throw StackException("stack::pop");

        }
        else {
            ListNode* temp = _head;
            _head = _head->next;
            delete temp;
            _size--;
        }

    }
	private:
	struct ListNode {
		T item;
		ListNode* next = nullptr;

    };
	ListNode* _head;
	int _size;
};

#endif //ASSIGNMENT3_STACK_H

	
