// Create a function that will reverse a string
function reverse_1(str) {

	// Validate input if it is a string
	if (typeof str !== "string") {
		throw "the input is not a string";
	}

	// Create an array to store the string's characters in reverse 
	const backwards = [];

	// Iterate through each character in the string backwards and store it in the array
	for (let i = str.length - 1; i >= 0; --i) {
		backwards.push(str[i]);
	}

	// Convert the array into string
	return backwards.join('');
}

const reverse_2 = str => str.split('').reverse().join('');

original = "Hello! My name is Zeus";

console.log(`Original: ${original}`);

t10 = performance.now();
reverse_result_1 = reverse_1(original);
t11 = performance.now();
t20 = performance.now();
reverse_result_2 = reverse_2(original);
t21 = performance.now();
console.log(`Time (ms): ${(t11-t10)}`);
console.log(`Time (ms): ${(t21-t20)}`);

console.log(`Result (reverse_1): "${reverse_result_1}"`);
console.log(`Result (reverse_2): "${reverse_result_2}`);

