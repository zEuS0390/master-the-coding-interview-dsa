#include <iostream>

using namespace std;

// Using recursive approach
int findFactorialRecursive(int number) {
	if (number <= 1) return 1;
	return number * findFactorialRecursive(number - 1);
}

// Using iterative approach
int findFactorialIterative(int number) {
	int result = 1;
	while (number > 0)
		result *= number--;
	return result;
}

// Main function
int main(int argc, char* argv[]) {
	int result = findFactorialRecursive(12);
	cout << result << endl;
	return 0;
}
