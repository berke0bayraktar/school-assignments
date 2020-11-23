#include <iostream>

using namespace std;

class Array2 {
    int ROW;
    int COL;
    int* arr;
public:
    Array2(int ROW, int COL) : ROW(ROW), COL(COL) {
        arr = new int[ROW*COL];
    }

    int Get(int i, int j) {
        int idx = i*COL + j;
        return arr[idx];
    }

    void Put(int i, int j, int x) {
        int idx = i*COL + j;
        arr[idx] = x;
    }

    ~Array2() {
        delete[] arr;
    }
};

class LTM {
    int SIZE, *arr;

public:
    LTM(int size) : SIZE((size+1)*size/2) {
        arr = new int[SIZE];
    }
    int Get(int i, int j) {
        int idx = i*(i+1)/2 + j;
        return arr[idx];
    }
    void Put(int i, int j, int val) {
        int idx = i*(i+1)/2 + j;
        arr[idx] = val;
    }
    ~LTM() {
        delete[] arr;
    }
};


int main() {
    LTM ltm(5);
    for(int i=0; i<5; i++) {
        for(int j=0; j<=i; j++) {
            int x; cin >> x;
            ltm.Put(i,j,x);
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<=i; j++){
            cout << ltm.Get(i,j) << " ";
        }
        cout << endl;
    }
}
