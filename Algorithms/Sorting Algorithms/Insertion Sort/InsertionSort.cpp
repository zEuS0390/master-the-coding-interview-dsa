#include <iostream>

using namespace std;

void print(int* arr, int length) {
	for (int i = 0; i < length; ++i) 
		cout << arr[i] << ((i != length - 1)? ", ":"");
	cout << endl;
}

// Insertion Sort Algorithm
//
// Time Complexity:
// - Best Case: O(N)
// - Average Case: O(N^2)
// - Worst Case: O(N^2)
//
// Space Complexity: O(N)
void insertionSort1(int* arr, int length) {
	for (int i = 0; i < length; ++i) {
		int tmp = arr[i];
		for (int j = i-1; j >= 0; --j) {
			if (tmp < arr[j]) {
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void insertionSort2(int* arr, int length) {
	for (int i = 1; i < length; i++) {
		if (arr[i] < arr[i-1]) {
			int tmp = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > tmp) {
				arr[j+1] = arr[j];
				--j;
			}
			arr[j+1] = tmp;
		}
	}
}

int main(int argc, char* argv[]) {
	int arr[] = {9, 8, -1, 0, 6, 45, 100, 32, 55, 42, 15};
	int length = sizeof(arr)/sizeof(arr[0]);

	cout << "Unsorted Array: ";
	print(arr, length);

	insertionSort2(arr, length);

	cout << "Sorted Array: ";
	print(arr, length);
	return 0;
}
