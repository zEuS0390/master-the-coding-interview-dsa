#include <unordered_map>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

// Dynamic Programming Leetcode Problem: https://leetcode.com/problems/house-robber/

// Recursive Approach
// Efficiency:
// Time Complexity: O(N)
// Space Complexity: O(N) but it might have a higher overhead due to recursive calls and function stack
int robRecursive(vector<int>& nums) {

	function<int(vector<int>&, int, unordered_map<int, int>&)> robHelper;
        unordered_map<int, int> cache;

        robHelper = [&robHelper](vector<int>& nums, int index, unordered_map<int, int>& cache) {

            if (index >= nums.size()) return 0;
            if (cache.find(index) != cache.end()) return cache[index];

            int rob_current = nums[index] + robHelper(nums, index + 2, cache);
            int rob_skipped = robHelper(nums, index + 1, cache);

            cache[index] = max(rob_current, rob_skipped);

            return cache[index];
        };

        return robHelper(nums, 0, cache);
}

// Iterative Approach (Better)
// Efficiency;
// Time Complexity: O(N)
// Space Complexity: O(N)
int rob(vector<int>& nums) {

	int length = nums.size();

	if (length == 0)
		return 0;

	if (length == 1)
		return nums[0];

	vector<int> dP(length);

	dP[0] = nums[0];
	dP[1] = max(nums[0], nums[1]);

	for (int i = 2; i < length; ++i)
		dP[i] = max(nums[i] + dP[i - 2], dP[i - 1]);

	return dP[length-1];
}

// Main function
int main(int argc, char* argv[]) {
	vector<int> nums = {2,7,9,3,1};
	cout << "Iterative Approach: " << rob(nums) << endl;
	cout << "Recursive Approach: " << robRecursive(nums) << endl;
	return 0;
}
