/*
4. Find the first non-repeating element in an array using a hash map.
Input:
[4, 5, 1, 2, 0, 4]
Output:
5
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstNonRepeating(const vector<int>& nums) {
    unordered_map<int, int> freq;

    // Count frequency
    for (int x : nums)
        freq[x]++;

    // Find first non-repeating element
    for (int x : nums) {
        if (freq[x] == 1)
            return x;
    }
    return -1;  // if no non-repeating element exists
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};

    int ans = firstNonRepeating(nums);
    if (ans != -1)
        cout << ans;
    else
        cout << "No non-repeating element found";

    return 0;
}

/*
✅ Sample Input
[4, 5, 1, 2, 0, 4]

 Sample Output
5
*/