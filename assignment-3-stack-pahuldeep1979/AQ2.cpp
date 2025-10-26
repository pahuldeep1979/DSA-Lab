#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0'; 
    }
};

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Stack s;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string reversed = "";              // output string
    while (!s.isEmpty()) {
        reversed += s.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
