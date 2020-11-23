#include <iostream>
#include <list>
using namespace std;

struct Triplet {
    int a,b,c;
    Triplet() : a(0), b(0), c(0) {}
    Triplet(int a, int b, int c) : a(a), b(b), c(c) { }
};

list<Triplet> Convert2DArrayToSparseMatrix(int **array, int rows, int cols) {
    list<Triplet> sparse;
    int count = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if (array[i][j] != 0) {
                sparse.push_back(Triplet(i,j,array[i][j]));
                count++;
            }
        }
    }

    sparse.push_front(Triplet(rows,cols,count));
    return sparse;
}

int main() {
    int rows=3,cols=8;
    int** array = new int*[rows];

    for(int i=0; i<rows; i++) {
        array[i] = new int[cols];
    }

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cin >> array[i][j];
        }
    }

    list<Triplet> result = Convert2DArrayToSparseMatrix(array, rows, cols);

    auto it = result.begin();

    while (it != result.end()) {
        cout << it->a << " " << it->b << " " << it->c << endl;
        it++; 
    }
}
