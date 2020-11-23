#include <iostream>

using namespace std;

void TwoMax(int **arr, int rows, int cols, int* first, int* second) {
    *first=INT32_MIN, *second=INT32_MIN;

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int value = arr[i][j];
            if (value > *first) {
                *second = *first;
                *first = value;
            }
        }
    }
}

int main() {
    int first=0,second=0,**array;
    int rows=3,cols=3;
    array = (int**) malloc(rows*sizeof(int));

    for(int i=0; i<rows; i++) {
        int* temp = (int*) malloc(cols*sizeof(int));
        array[i] = temp;
    }

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cin >> array[i][j];
        }
    }

    TwoMax(array, rows, cols, &first, &second);

    cout << "first: " << first << endl;
    cout << "second: " << second << endl;
}
