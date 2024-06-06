#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <vector>

// A function that returns indices of two numbers in the array that add up to the target number
std::vector<int> twoSum(const std::vector<int>& nums, int target) {

	// Hash table to store the known numbers
	std::unordered_map<int, int> known;

	// Iterate through each number in the array
	for (int index = 0; index < nums.size(); ++index) {

		const int current_number = nums[index];

		// Calculate the complement of the current number relative to the target number
		const int complement = target - current_number;

		// Return the indices of the two numbers if the complement is in the hash table
		if (known.find(complement) != known.end())
			return {known[complement], index};

		// Store the index of the current number in the hash table
		known[current_number] = index;
	}
	return {};
}

// Main function
int main(int argc, char *argv[]) {

	if (argc < 4) {
		std::cerr << "Usage: " << argv[0] << " <target> <num1> <num2> ..." << std::endl;
		std::cerr << "Example: " << argv[0] << " 9 5 4 1 3\nOutput: [0,1]" << std::endl;
		return 1;
	}

	const int target = std::stoi(argv[1]);
	std::vector<int> nums;
	
	for (int i = 2; i < argc; ++i) 
		nums.push_back(std::stoi(argv[i]));

	std::vector<int> output = twoSum(nums, target);
	
	if (output.empty()) {
		std::cout << "No solution found." << std::endl;
		return 0;
	}
	
	std::cout << "[";
	for (int i = 0; i < output.size(); ++i) {
		std::cout << output[i];
		if (i != output.size()-1)
			std::cout << ",";
	}
	std::cout << "]" << std::endl;
	return 0;
}
