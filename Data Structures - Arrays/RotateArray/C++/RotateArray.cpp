#include <iostream>
#include <vector>

using namespace std;

// Least Efficient Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
void rotate1(vector<int>& nums, int k) {
	int length = nums.size();
	vector<int> result(length);
	for (int index = 0; index < length; ++index) {
		int rotated_index = (index + k) % length;
		result[rotated_index] = nums[index];
	}
	nums = result;
}

// Most Efficient Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
void rotate2(vector<int>& nums, int k) {
	int length = nums.size();
	k = k % length;

	int left = 0, right = length - 1;
	auto swap = [](int& n1, int& n2) {
		int temp = n2;
		n2 = n1;
		n1 = temp;
	};

	auto reverse = [&nums, swap](int left, int right) {
		while (left < right) {
			swap(nums[left], nums[right]);
			++left; --right;
		}
	};

	reverse(0, length-1);
	reverse(0, k-1);
	reverse(k, length-1);
}

void print(vector<int>& nums, int k) {
	cout << "nums = [";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size()-1)? ", ": "");
	cout << "], k = " << k << "\n";
}

// Main function
int main(int argc, char* argv[]) {
	vector<int> nums1 = {1,2,3,4,5,6,7};
	rotate1(nums1, 3);
	cout << "Least Efficient Solution (rotate1): ";
	print(nums1, 3);

	vector<int> nums2 = {1,2,3,4,5,6,7};
	rotate2(nums2, 20);
	cout << "Most Efficient Solution (rotate2): ";
	print(nums2, 20);
	return 0;
}
