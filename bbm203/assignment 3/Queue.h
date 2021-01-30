#ifndef ASSIGNMENT3_QUEUE_H
#define ASSIGNMENT3_QUEUE_H


/*Function templates are special functions that can operate
with generic types. This allows us to create a function 
template whose functionality can be adapted to more than 
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);
*/

#include "QueueException.h"

template<typename T>
class Queue {
	public:
	Queue() {
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }
	~Queue() {
        QueueNode* temp = _head;
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
	//Enqueue: Items are added to the back of the queue
	void enqueue(const T& newItem) {
        QueueNode* newNode = new QueueNode;
        newNode->item = newItem;

        if (isEmpty()) {
            _head = newNode;
            _tail = newNode;
        }
        else {
            _tail->next = newNode;
            _tail = newNode;
        }

        _size++;
    }
	//Dequeue: Items are removed from the front of the queue
	void dequeue() {
        if(isEmpty()) {
            throw QueueException("queue::dequeue");
        }
        else {
            QueueNode* temp = _head;
            _head = _head->next;
            delete temp;
            _size--;

            if (isEmpty()) {
                _tail = nullptr;
            }

        }
    }
	//Get Front: Take a look at the first item
	void getFront(T& queueTop) const {
        if (isEmpty()) {
            throw QueueException("queue::getFront");
        }
        else {
            queueTop = _head->item;
        }
    }

	private:
	struct QueueNode {
		T item;
		QueueNode *next = nullptr;
		};
	int _size;
	/* to avoid the traversal to the last node, 
	 an additional pointer to the last node is defined*/
	QueueNode *_tail;
	QueueNode *_head;
};

#endif //ASSIGNMENT3_QUEUE_H