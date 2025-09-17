/* Roll no :1024030982 , assignment completed */
// Q5. Write a program to implement a stack using (a) Two queues
#include <iostream>
#include <queue>
using namespace std;

class Stack2Q_CostlyPush {
    queue<int> q1, q2;
public:
    void push(int x) {
        // Step 1: move everything from q1 -> q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Step 2: push new element to q1
        q1.push(x);
        // Step 3: move everything back q2 -> q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if (q1.empty()) {
            cout << "Underflow! Stack is empty.\n";
            return;
        }
        q1.pop();
    }

    int top() const {
        if (q1.empty()) {
            cout << "Stack is empty.\n";
            return -1; // or throw
        }
        return q1.front();
    }

    bool empty() const { return q1.empty(); }
    int size()  const { return (int)q1.size(); }
};

class Stack2Q_CostlyPop {
    queue<int> q1, q2;
public:
    void push(int x) {
        // O(1) push
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Underflow! Stack is empty.\n";
            return;
        }
        // Move until last element remains in q1
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        // Last element is the "top"
        q1.pop(); // discard
        // swap q1 and q2
        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty.\n";
            return -1; // or throw
        }
        // Move until last element remains in q1
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front(); // top element
        // Put it into q2 (since top() shouldn't remove it)
        q2.push(ans);
        q1.pop();
        // Restore: swap q1 and q2
        swap(q1, q2);
        return ans;
    }

    bool empty() const { return q1.empty(); }
    int size()  const { return (int)q1.size(); }
};

int main() {
    cout << "=== Stack using Two Queues (Costly PUSH) ===\n";
    Stack2Q_CostlyPush s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);          // stack top should be 30
    cout << "Top: " << s1.top() << "\n"; // 30
    s1.pop();                              
    cout << "Top after pop: " << s1.top() << "\n"; // 20
    s1.push(40);
    cout << "Top after push(40): " << s1.top() << "\n"; // 40

    cout << "\n=== Stack using Two Queues (Costly POP) ===\n";
    Stack2Q_CostlyPop s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);          // stack top should be 30
    cout << "Top: " << s2.top() << "\n"; // 30
    s2.pop();                              
    cout << "Top after pop: " << s2.top() << "\n"; // 20
    s2.push(40);
    cout << "Top after push(40): " << s2.top() << "\n"; // 40

    return 0;
}

