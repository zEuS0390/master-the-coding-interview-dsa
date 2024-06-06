#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr, const char* end = "\n") {
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << ((i != arr.size()-1)? ", ": "");
	cout << end;
}

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;

	int left_index = 0;
	int right_index = 0;

	while (left_index < left.size() && right_index < right.size()) {
		if (left[left_index] < right[right_index])
			result.push_back(left[left_index++]);
		else
			result.push_back(right[right_index++]);
	}

	while (left_index < left.size())
		result.push_back(left[left_index++]);

	while (right_index < right.size())
		result.push_back(right[right_index++]);

	return result;
}

vector<int> mergeSort(vector<int> arr) {

	// Base case
	if (arr.size() <= 1)
		return arr;

	int middle = arr.size() / 2;

	vector<int> left;
	vector<int> right;

	for (int i = 0; i < middle; ++i)
		left.push_back(arr[i]);

	for (int i = middle; i < arr.size(); ++i)
		right.push_back(arr[i]);

	print(left, "");
	cout << " | ";
	print(right);

	return merge(mergeSort(left), mergeSort(right));
}


// Main function
int main(int argc, char* argv[]) {
	vector<int> arr = {100, 9, 10, 1, 32, -1, 0, 45};
	vector<int> sorted_arr = mergeSort(arr);
	cout << "Unsorted Array: ";
	print(arr);
	cout << "Sorted Array: ";
	print(sorted_arr);
	return 0;
}
