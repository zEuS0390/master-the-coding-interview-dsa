#include <iostream>
#include <cstring>

using namespace std;

// Create a function that will reverse a string 
const char* reverse(const char* str) {

	const int length = strlen(str);

	// Create a char array to store the string's characters in reverse 
	char* backwards = new char[length + 1]; // +1 for the null terminator

	// Create a variable to hold the current position of the backwards char array
	int backwardspos = 0;

	// Iterate through each character in the string backwards and store it in the array
	for (int index = length - 1; index >= 0; --index, ++backwardspos)
		backwards[backwardspos] = str[index];

	// Add null terminator
	backwards[length + 1] = '\n';

	// Return the backwards char array
	return backwards;

}

int main(int argc, char* argv[]) {
	const char* input = "Data Structures and Algorithms + C++ Programming Language";
	const char* output = reverse(input);
	cout << output << endl;
	// Deallocate memory
	delete[] output;
	return 0;
}
