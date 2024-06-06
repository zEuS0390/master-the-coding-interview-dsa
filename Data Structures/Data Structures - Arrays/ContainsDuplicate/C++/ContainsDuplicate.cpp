#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
	unordered_set<int> known;
	for (const int n: nums) {
	    if (known.find(n) != known.end())
		return true;
	    known.insert(n);
	}
	return false;
}

// Main function
int main(int argc, char* argv[]) {
	vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
	cout << (containsDuplicate(nums)? "true" : "false") << endl;
	return 0;
}
