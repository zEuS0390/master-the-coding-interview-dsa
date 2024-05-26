#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

bool containsCommonItem(vector<char>& arr1, vector<char>& arr2) {
	for (int i = 0; i < arr1.size(); ++i) {
		for (int j = 0; j < arr2.size(); ++j) {
			if (arr1[i] == arr2[j]) {
				return true;
			}
		}
	}
	return false;
} // O(n^2)

bool containsCommonItem2(vector<char>& arr1, vector<char>& arr2) {
	unordered_map<char, bool> hash_table;
	for (const auto& item: arr1) {
		if (hash_table.find(item) == hash_table.end())
			hash_table[item] = true;
	}
	for (const auto& item: arr2) {
		if (hash_table.find(item) != hash_table.end())
			return true;
	}
	return false;	
} // O(n) <-- Most efficient

// Main function
int main(int argc, char* argv[]) {
	vector<char> arr1 = {'a', 'b', 'c', 'x'};
	vector<char> arr2 = {'z', 'y', 'x'};
	bool result = containsCommonItem2(arr1, arr2);
	cout << (result? "true": "false") << endl;
	return 0;
}
