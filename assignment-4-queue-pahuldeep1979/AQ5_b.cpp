/* Roll no :1024030982 , assignment completed */
// Q5.(b). Write a program to implement a stack using (a) one  queue

#include <iostream>
#include <queue>
using namespace std;

// Stack implemented with ONE queue (costly push).
class Stack1Q {
    queue<int> q;

public:
    void push(int x) {
        // 1) Enqueue new element
        size_t n = q.size();
        q.push(x);
        // 2) Rotate the previous n elements to the back,
        //    so the new element comes to the FRONT.
        while (n--) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Underflow! Stack is empty.\n";
            return;
        }
        // Front is the current "top"
        q.pop();
    }

    int top() const {
        if (q.empty()) {
            cout << "Stack is empty.\n";
            return -1; // or throw
        }
        return q.front();
    }

    bool empty() const { return q.empty(); }
    int  size()  const { return (int)q.size(); }
};

int main() {
    Stack1Q s;
    s.push(10);        // stack: [10]
    s.push(20);        // stack: [20, 10]
    s.push(30);        // stack: [30, 20, 10]

    cout << "Top: " << s.top() << "\n";       // 30
    s.pop();                                   // stack: [20, 10]
    cout << "Top after pop: " << s.top() << "\n";   // 20
    s.push(40);                                // stack: [40, 20, 10]
    cout << "Top after push(40): " << s.top() << "\n"; // 40
}

