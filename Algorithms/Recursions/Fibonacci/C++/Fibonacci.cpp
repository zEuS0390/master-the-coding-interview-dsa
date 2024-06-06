#include <iostream>

using namespace std;

// Time Complexity (Best)
// O(N) Linear Time
int fibonacciIterative(int n) {

	/*
	Method 1:

	int array[n+1];
	int length = 0;

	int a = 0;
	int b = 1;
	int c = a + b;

	while (n > 0) {
		a = b;
		b = c;
		c = a + b;
		array[length++] = a;
		n--;
	}

	return array[length-1];
	*/

	/*
	Method 2: 
	*/
	int array[n+1];

	array[0] = 0;
	array[1] = 1;

	for (int i = 2; i < n+1; ++i)
		array[i] = array[i-2] + array[i-1];

	return array[n];
}

// Time Complexity (Worst): 
// O(2^N) Exponential Time
int fibonacciRecursive(int n) {
	if (n <= 1)
		return n;
	return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Main function
int main(int argc, char* argv[]) {
	int result = fibonacciIterative(10);
	cout << result << endl;
	return 0;
}

