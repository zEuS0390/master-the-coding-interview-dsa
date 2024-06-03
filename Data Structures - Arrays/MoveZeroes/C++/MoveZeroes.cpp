#include <iostream>
#include <vector>

using namespace std;

// Least efficient solution: O(n^2)
void moveZeroes1(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == 0) {
			nums.erase(nums.begin() + i);
			nums.push_back(0);
		}
	}
}

// Most efficient solution: O(n)
void moveZeroes2(vector<int>& nums) {

	// Current position of the non-zero number
	int NonZeroPos = 0;

	// Iterate through the array and move the non-zero numbers at the front
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] != 0)
			nums[NonZeroPos++] = nums[i];
	}

	// Iterate through the array starting at the last non-zero number position and fill the remaining positions with zeroes
	for (int i = NonZeroPos; i < nums.size(); ++i)
		nums[i] = 0;
}

void print(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i];
		cout << ((i != nums.size()-1)? ", " : "\n");
	}
}

// Main function
int main(int argc, char* argv[]) {
	vector<int> nums1 = {0, 1, 0, 3, 12};
	moveZeroes1(nums1);
	cout << "Least Efficient Solution: ";
	print(nums1);

	vector<int> nums2 = {0, 1, 0, 3, 12};
	moveZeroes2(nums2);
	cout << "Most Efficient Solution: ";
	print(nums2);
	return 0;
}
