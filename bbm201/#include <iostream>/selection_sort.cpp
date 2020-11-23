#include <iostream>

/*returns the minimum element inside an array for a given range.
*n: size of the array
*i: start (inclusive)
*j: end (exclusive)*/

int minIndex(int* arr, int n, int i, int j) {
	int minIndex = i; 
	for (int m = i; m < j; m++) {
		if (*(arr + m) < *(arr + minIndex)) {
			minIndex = m; 
		}
	}
	return minIndex; 
}

void swap(int* arr, int i, int j) {
	int temp = *(arr + i);
	*(arr + i) = *(arr + j); 
	*(arr + j) = temp; 
}

void selectionSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = minIndex(arr, n, i, n);
		swap(arr, i, min_idx); 
	}
}

int main() {
	const int arrSize = 7;

	int* arr = new int[arrSize]{ 7,4,8,9,1,2,3 };

	selectionSort(arr, arrSize);
	
	for (int i = 0; i < arrSize; i++) {
		std::cout << *(arr + i) << " "; 
	}
}
