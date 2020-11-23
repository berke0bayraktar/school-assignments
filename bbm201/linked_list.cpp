#include <iostream>
#include <list>
//Singly Linked List HEAD

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data): data(data), next(nullptr) {}
    Node(): data(0), next(nullptr) {}
};

class LinkedList {
private:
    Node* head = nullptr;

    void PrintReverseAux(Node* node) {
        if (node == nullptr) return;
        PrintReverseAux(node->next);
        cout << node->data << " ";
    }

    Node* ReverseRecAux(Node* curr) {
        if(curr == nullptr || curr->next == nullptr) {
            head = curr;
            return curr;
        }
        Node* reversed = ReverseRecAux(curr->next);
        reversed->next = curr;
        curr->next = nullptr;
        return curr;
    }

public:
    void PushFront(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
    }
    void Print() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void Insert(int n, int x) {
        Node* temp = new Node(x);
        if (n == 0) {
            temp->next = head;
            head = temp;
            return;
        }
        Node* temp2 = head;
        for(int i=0; i<n-1; i++) {
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }
    void Remove(int n) {
        Node* temp = head;

        if(n == 0) {
            head = head->next;
            delete temp;
            return;
        }

        for(int i=0; i<n-1; i++) {
            temp = temp->next;
        }
        Node* nodeToRemove = temp->next;
        temp->next = nodeToRemove->next;
        delete nodeToRemove;
    }
    void ReverseIter() {
        Node *prev, *curr=nullptr, *nxt=head;
        while(nxt != nullptr) {
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            curr->next = prev;
        }
        head = curr;
    }

    void ReverseRec() {
        ReverseRecAux(head);
    }

    void PrintReverse() {
        PrintReverseAux(head);
    }

    void Join(LinkedList otherList) {
        if (head == nullptr) {
            head = otherList.head;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = otherList.head;
    }
};

list<pair<int,int>> AddPolynomials(list<pair<int,int>>& p1, list<pair<int,int>>& p2) {
    list<pair<int,int>> result;

    list<pair<int,int>>& bigger = p1.size()>=p2.size() ? p1:p2;
    list<pair<int,int>>& smaller = p1.size()>=p2.size() ? p2:p1;

    auto bit = bigger.begin();
    auto sit = smaller.begin();

    while(sit != smaller.end()) {
        // if exponents are equal add coefficients create new term move both
        if (bit->second == sit->second) {
            pair<int,int> newTerm = {bit->first+sit->first, bit->second};
            result.push_back(newTerm);
            bit++; sit++;
        }
        else if (bit->second > sit->second) {
            pair<int,int> duplicate = *sit;
            result.push_back(duplicate);
            sit++;
        }
        else {
            pair<int,int> duplicate = *bit;
            result.push_back(duplicate);
            bit++;
        }
    }

    while(bit != bigger.end()) {
        result.push_back(*bit);
        bit++;
    }
    return result;
}

int main() {
    LinkedList list1;
    LinkedList list2;
}
