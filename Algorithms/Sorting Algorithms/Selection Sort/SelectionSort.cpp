#include <iostream>

using namespace std;

void swap(int& num1, int& num2) {
	int tmp = num2;
	num2 = num1;
	num1 = tmp;
}

void print(int* arr, int length) {
	for (int i = 0; i < length; ++i)
		cout << arr[i] << ((i != length-1)? ", ": "");
	cout << endl;
}

void selectionSort(int* arr, int length) {
	for (int i = 0; i < length; ++i) {
		int min = i;
		for (int j = i; j < length; ++j) {
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

// Main function
int main(int argc, char* argv[]) {
	int arr[] = {5, 9, 32, -1, 0, 45, 100, 79, 1, 32, 2, 99};
	int length = sizeof(arr)/sizeof(arr[0]);

	cout << "Unsorted Array: ";
	print(arr, length);

	selectionSort(arr, length);

	cout << "Sorted Array: ";
	print(arr, length);
	return 0;
}
