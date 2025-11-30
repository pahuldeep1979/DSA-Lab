/*
Count the frequency of each number in an array using a hash map.
Input:
nums = [2, 3, 2, 4, 3, 2]
Output:
• 2 → 3 times
• 3 → 2 times
• 4 → 1 time
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    unordered_map<int, int> freq;

    // Count frequency
    for (int x : nums) {
        freq[x]++;
    }

    // Print frequency
    for (auto &p : freq) {
        cout << p.first << " → " << p.second << " times" << endl;
    }

    return 0;
}

/*
 Sample Input
nums = [2, 3, 2, 4, 3, 2]
Sample Output
2 → 3 times
3 → 2 times
4 → 1 times
*/