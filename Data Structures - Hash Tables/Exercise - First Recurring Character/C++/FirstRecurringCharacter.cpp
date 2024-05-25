#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

template <typename T>
T firstRecurringChar(std::vector<T>& arr) {

	// Create a hash table that will store the number of recurring characters
	std::unordered_map<T, int> recurring_char_map;

	// Iterate through the array to find the recurring character
	for (const auto& item: arr) {

		// Increment the number of occurences in the hash table
		recurring_char_map[item]++;

		// Immediately return the character if it occured more than once
		if (recurring_char_map[item] > 1)
			return item;
	}

	// Throw a runtime error when no recurring character is found
	throw std::runtime_error("No recurring character found.");
}

// Main function
int main(int argc, char* argv[]) {
	std::vector<int> inputs = {2,3,4,5};
	try {
		int output = firstRecurringChar(inputs);
		std::cout << output << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "undefined" << std::endl;
		return 1;
	}
	return 0;
}
