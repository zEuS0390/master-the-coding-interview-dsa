#include <iostream>
#include <cstring>

using namespace std;

void reverseStringHelper(const char* string, char* reversed_string, int length, int index) {
	if (length < 0) {
		reversed_string[index] = '\0';
		return;
	}
	reversed_string[index] = string[length];
	reverseStringHelper(string, reversed_string, length - 1, index + 1);
}

const char* reverseString(const char* string) {
	int length = strlen(string);
	char* reversed_string = new char[length+1];
	reverseStringHelper(string, reversed_string, length-1, 0);
	return reversed_string;
}

// Main function
int main(int argc, char* argv[]) {
	const char* string = "Hello World!";
	const char* reversed_string = reverseString(string);
	cout << "Original String: " << string << endl;
	cout << "Reversed String: " << reversed_string << endl;
	delete[] reversed_string;
	return 0;
}
