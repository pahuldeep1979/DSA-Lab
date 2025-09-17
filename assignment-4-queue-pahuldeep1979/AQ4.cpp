/* Roll no :1024030982 , assignment completed */
// Q4.  Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a b c Sample O/P: a -1 b b 
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Prints first non-repeating char after each input char in the stream.
// Spaces are ignored so the sample "a a b c" matches "a -1 b b".
int main() {
    string s;
    getline(cin, s);             // e.g. input line:  a a b c

    queue<char> q;               // holds candidates that might be first non-repeating
    int freq[256] = {0};         // ASCII frequency (constant space)

    bool first = true;
    for (char ch : s) {
        if (ch == ' ') continue; // ignore spaces (to match the sample format)

        // update state for this new character
        freq[(unsigned char)ch]++;
        q.push(ch);

        // pop from front until the front is truly non-repeating
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) {
            q.pop();
        }

        // print answer for this step
        if (!first) cout << ' ';
        first = false;

        if (q.empty()) cout << -1;
        else           cout << q.front();
    }
    cout << '\n';
    return 0;
}
