#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = val;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Peek\n6. Display\n7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> val;
                s.push(val);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;

            case 4:
                cout << (s.isFull() ? "Stack is full" : "Stack is not full") << endl;
                break;

            case 5:
                s.peek();
                break;

            case 6:
                s.display();
                break;

            case 7:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
