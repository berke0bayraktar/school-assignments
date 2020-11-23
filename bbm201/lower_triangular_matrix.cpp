#include <iostream>
#include <cstring>

using namespace std;

int* GetLTM(int n) {
    int size = n*(n+1)/2;
    int* ltm = new int[size];
    memset(ltm,0,size*sizeof(int));
    return ltm;
}

int LTM(int i, int j) {
    return i*(i+1)/2 + j;
}

int main() {
    int SIZE;
    cin >> SIZE;
    int *ltm=GetLTM(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << ltm[LTM(i,j)] << " ";
        }
        cout << endl;
    }
}
