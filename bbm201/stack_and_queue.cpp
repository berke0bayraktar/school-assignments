#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

class ArrayStack {

private:
    const static int MAX_SIZE = 10;
    int stack[MAX_SIZE];
    int top = -1;

public:

    ArrayStack() : stack() {}

    int Full() {
        return top+1 == MAX_SIZE;
    }
    int Empty() {
        return top == -1;
    }

    int Push(int x) {
        if (Full()) return 0;
        stack[++top] = x;
        return 1;
    }

    int Top() {
        return stack[top];
    }


    int Pop() {
        if (Empty()) return 0;
        top--;
        return 1;
    }

    void Print() {
        for(int i=0; i<=top; i++) {
            cout << stack[i] << " ";
        }
    }
};

int CheckParentheses(string s) {
    stack<char> stk;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        }
        else {
            if (stk.empty()) return 0;
            char lastSymbol = stk.top();
            if ((c == ')' && lastSymbol == '(') ||
                (c == '}' && lastSymbol == '{') ||
                (c == ']' && lastSymbol == '[')) {
                stk.pop();
            }
            else return false;
        }
    }
    return stk.empty();
}

class ArrayQueue {
private:
    static const int MAX_SIZE = 10;
    int queue[MAX_SIZE];
    int front=-1, rear =-1;
public:
    ArrayQueue() : queue() {}
    int IsEmpty() {
        return front == -1 && rear == -1;
    }
    int IsFull() {
        return rear-front+1 == MAX_SIZE;
    }

    int Enqueue(int x) {
        if (IsFull()) return 0;
        if (IsEmpty()) {
            front++;
        }
        if (rear == MAX_SIZE -1 && !IsFull()) {
            int size = rear-front+1;
            memcpy(queue, queue+front, size*sizeof(int));
            front = 0;
            rear = size-1;
        }
        queue[++rear] = x;
        return 1;
    }

    int Dequeue() {
        if (IsEmpty()) return 0;
        if (front == rear) {
            front=-1; rear=-1;
        }
        else {
            front++;
        }
        return 1;
    }
    int Front() {
       if(IsEmpty()) {
           return -1;
       }
       return queue[front];
    }
    void Print() {
        for(int i=front; i<=rear; i++) {
            cout << queue[i] << " ";
        }
    }
};

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
    Node() : data(0), next(nullptr) {}
};

class LinkedStack {
private:
    Node* top = nullptr;
public:
    void Push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }
    int Pop() {
        if (top == nullptr) return 0;
        Node* temp = top;
        top=top->next;
        delete temp;
        return 1;
    }
    int Top() {
        return top->data;
    }
    void Print() {
        Node* temp = top;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

string ReverseStringWithStack(string s) {
    stack<char> stk;
    for(int i=0; i<s.size(); i++){
        stk.push(s[i]);
    }
    string ns;
    int size = stk.size();
    for(int i=0; i<size; i++){
        ns.push_back(stk.top());
        stk.pop();
    }
    return ns;
}

class LinkedQueue {
private:
    Node* front = nullptr, *rear=nullptr;
public:
    void Enqueue(int x) {
        Node* temp = new Node(x);
        if (front == nullptr && rear == nullptr) {
            front = temp; rear=temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    int Dequeue() {
        if (front == nullptr && rear == nullptr) {
            return 0;
        }
        if (front == rear) {
            front=nullptr; rear=nullptr;
            return 1;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        return 1;
    }
    void Print() {
        Node* temp = front;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

int main() {

}
