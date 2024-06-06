const firstRecurringChar = (arr) => {
	recurring_char_map = {};
	for (const item of arr) {
		recurring_char_map[item] = (recurring_char_map[item] || 0) + 1;
		if (recurring_char_map[item] > 1)
			return item
	}
	return undefined;
}

const input = [2,3,4,5];
const result = firstRecurringChar(input);
console.log(result);

