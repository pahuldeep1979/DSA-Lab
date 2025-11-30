/*Given an integer array, check if it contains any duplicates using hash set.
Input:
nums = [1, 2, 3, 1]
Output:
true
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> s;

    for (int x : nums) {
        if (s.find(x) != s.end()) {
            return true;   // duplicate found
        }
        s.insert(x);
    }
    return false; // no duplicates
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    if (containsDuplicate(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}

/*
nums = [1, 2, 3, 1]
true

*/