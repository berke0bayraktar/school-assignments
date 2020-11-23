#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int item, int* list, int size, int left, int right) {
    if(left>right){
        return -1;
    }
    int middle=(left+right)/2;
    if (list[middle]==item){
        return middle;
    }
    else if (item>list[middle]) {
        //search to right
        return BinarySearch(item, list, size, middle+1, right);
    }
    else {
        //search to left
        return BinarySearch(item, list, size, left, middle-1);
    }
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
        cout << "item is at: " << BinarySearch(item, list, size, 0, size-1) << endl;
    } while(item != -1);
}
