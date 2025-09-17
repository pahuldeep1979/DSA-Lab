/* Roll no :1024030982 , assignment completed */
// Ques3. Write a program interleave the first half of the queue with second half. Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9 
#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even to interleave!" << endl;
        return;
    }

    int half = n / 2;
    queue<int> temp;

    // Step 1: Move first half into temp
    for (int i = 0; i < half; i++) {
        temp.push(q.front());
        q.pop();
    }

    // Step 2: Interleave
    while (!temp.empty()) {
        // take from first half
        q.push(temp.front());
        temp.pop();

        // take from second half
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    queue<int> qcopy = q;
    while (!qcopy.empty()) {
        cout << qcopy.front() << " ";
        qcopy.pop();
    }
    cout << endl;

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
