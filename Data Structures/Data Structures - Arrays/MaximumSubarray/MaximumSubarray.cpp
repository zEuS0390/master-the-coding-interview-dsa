#include <iostream>
#include <algorithm>
#include <vector>

// A function that gets the maximum sum of subarray (Using kadane's Algorithm)
int maximumSubarray(std::vector<int>& nums) {

	// Maximum sum of subarray
	int maximum_subarray_sum = nums[0];

	// Accumulated sum of a certain subarray
	int current_sum = 0;

	// Iterate through the array
	for (int i = 0; i < nums.size(); ++i) {

		// Reset current sum if it is negative
		if (current_sum < 0) {
			current_sum = 0;
		}

		// Add the current element in the current sum
		current_sum += nums[i];

		// Get the maximum value by comparing the two (current_sum, maximum_subarray_sum)
		maximum_subarray_sum = std::max(current_sum, maximum_subarray_sum);
	}	

	// Return the maximum sum of subarray
	return maximum_subarray_sum;
}

// Main function
int main(int argc, char* argv[]) {
	std::vector<int> nums = {5, 4, -1, 7, 8};
	int sum = maximumSubarray(nums);
	std::cout << sum << std::endl;
	return 0;
}
