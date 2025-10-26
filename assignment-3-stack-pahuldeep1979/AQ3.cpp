#include <iostream>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    char expr[100];
    cout << "Enter expression: ";
    cin >> expr;

    char stack[100];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatching(stack[top], ch)) {
                cout << "Not Balanced\n";
                return 0;
            }
            top--;
        }
    }

    if (top == -1)
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
