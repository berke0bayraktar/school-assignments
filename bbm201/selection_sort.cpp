#include <iostream>

int* GetList(int size) {
    int* list = new int[size];
    for(int i=0; i<size; i++) {
        list[i] = rand() % 100;
    }
    return list;
}

void SelectionSort(int* list, int size) {
    for(int i=0; i<size-1; i++) {
        int min = i;
        for(int j=i+1; j<size; j++) {
            if (list[j]<list[min]){
                min=j;
            }
        }
        int temp = list[i];
        list[i]=list[min];
        list[min]=temp;
    }
}

int main() {
    int size = 20;
    int* list = GetList(size);
    SelectionSort(list,size);

    for(int i=0; i<size; i++) {
        std::cout << list[i] << " ";
    }
}
