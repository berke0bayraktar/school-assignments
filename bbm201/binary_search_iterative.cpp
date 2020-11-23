#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int item, int* list, int size) {
    int left=0;
    int right=size-1;

    int middle;

    while(left<=right){
        middle = (left+right)/2;
        if (list[middle]==item) return middle;
        else if (item>list[middle]){
            left = middle+1;
        }
        else {
            right = middle-1;
        }
    }
    return -1;
}

int* GetSortedList(int size) {
    int* list = new int[size];
    for(int i=0; i<size; i++) {
        list[i] = rand() % 100;
    }
    sort(list, list+size);
    return list;
}

int main() {
    int size = 10;
    int* list = GetSortedList(size);

    for(int i=0; i<size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    int item;
    do {
        cin >> item;
        cout << "item is at: " << BinarySearch(item, list, size) << endl;
    } while(item != -1);
}
