// A function that returns indices of two numbers in the array that add up to the target number
const twoSum = (nums, target) => {

	// Hash table to store the known numbers
	const known = {};

	// Iterate through each number in the array
	for (let index = 0; index < nums.length; ++index) {

		// Current number
		const num = nums[index];

		// Calculate the complement of the current number relative to the target number
		const complement = target - num;

		// Return the indices of the two numbers if the complement is in the hash table
		if (complement in known) 
			return [known[complement], index];

		// Store the index of the current number in the hash table
		known[num] = index;
	}
	return [];
};

const output = twoSum([12, 16, 100, 200, 4, 75, 32, 98, 5], 9);
console.log(output);
