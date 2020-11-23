#include <iostream>


class CircularQueue {
    static const int SIZE = 10;
    int q[SIZE];
    int front=-1,rear=-1;
    CircularQueue() : q() {

    }

    void Enqueue(int x) {
        if ((front+1)%SIZE == rear) return;
        if (front == -1 && rear == -1) {
            front++;
        }
        q[(++rear)%SIZE] = x;
    }
    void Dequeue() {
        if (front == -1 && rear == -1) return;
        if (front == rear) front=-1; rear=-1;
        front = (front+1)%SIZE;

    }
};


int main() {
    std::cout << -1 % 4;
}
