/*
Given two arrays, find the common elements using a hash set.
Input:
A = [1, 2, 3, 4]
B = [3, 4, 5, 6]
Output:
3, 4
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findCommon(const vector<int>& A, const vector<int>& B) {
    unordered_set<int> s;
    vector<int> result;

    // Insert all elements of A into hash set
    for (int x : A)
        s.insert(x);

    // Check common elements in B
    for (int y : B) {
        if (s.find(y) != s.end()) {  // common found
            result.push_back(y);
        }
    }
    return result;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    vector<int> common = findCommon(A, B);

    cout << "Common elements: ";
    for (int x : common)
        cout << x << " ";

    return 0;
}

/*
Sample input : 
A = [1, 2, 3, 4]
B = [3, 4, 5, 6]
OUTPUT :
3 4

*/