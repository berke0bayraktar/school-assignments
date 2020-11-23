#include <iostream>

int GetMin(int idx, int* list, int size, int minIdx){
    if (idx == size) {
        return minIdx;
    }
    if (list[idx]<list[minIdx]) {
        return GetMin(idx+1, list, size, idx);
    }
    return GetMin(idx+1, list, size, minIdx);
}

void Swap(int i, int j, int* list) {
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void SelectionSort(int idx, int* list, int size) {
    if (idx == size) return;
    int minIdx = GetMin(idx+1, list, size, idx);
    Swap(idx, minIdx, list);
    SelectionSort(idx+1, list, size);
}

int* GetList(int size) {
    int* list = new int[size];
    for(int i=0; i<size; i++) {
        list[i] = rand() % 100;
    }
    return list;
}

int main() {
    int size = 10;
    int* list = GetList(size);
    SelectionSort(0, list, size);
    for(int i=0; i<size; i++) {
        std::cout << list[i] << " ";
    }
}
