#include <iostream>

using namespace std;

void swap(int& num1, int& num2) {
	int tmp = num2;
	num2 = num1;
	num1 = tmp;
}

void print(int* arr, int length) {
	for (int i = 0; i < length; ++i)
		cout << arr[i] << ((i != length-1)? ", ":" ");
	cout << endl;
}

// Bubble Sort Algorithm
//
// Time Complexity:
// - Best Case:		O(N)
// - Average Case:	O(N^2)
// - Worst Case:	O(N^2)
// 
// Space Complexity:	O(1)
void bubbleSort(int* arr, int length) {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length - i - 1; ++j) {
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}
}

// Main function
int main() {
	int arr[] = {5, 9, 8, 10, -1, 0};
	int length = sizeof(arr)/sizeof(arr[0]);

	cout << "Unsorted Array: ";
	print(arr, length);

	bubbleSort(arr, length);

	cout << "Sorted Array: ";
	print(arr, length);
	return 0;
}
