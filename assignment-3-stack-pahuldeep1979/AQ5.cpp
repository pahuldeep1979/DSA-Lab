#include <iostream>
using namespace std;

#define MAX 100

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int performOperation(int op1, int op2, char oper) {
    if (oper == '+') {
        return op1 + op2;
    } 
    else if (oper == '-') {
        return op1 - op2;
    } 
    else if (oper == '*') {
        return op1 * op2;
    } 
    else if (oper == '/') {
        return op1 / op2;  
    }
    return 0;
}

int main() {
    char postfix[MAX];
    int stack[MAX];
    int top = -1;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';
        } 
        else if (isOperator(c)) {
            if (top < 1) {
                cout << "Invalid Expression\n";
                return 1;
            }
            int op2 = stack[top--];
            int op1 = stack[top--];
            int result = performOperation(op1, op2, c);
            stack[++top] = result;
        }
    }

    if (top == 0) {
        cout << "Result: " << stack[top] << endl;
    } 
    else {
        cout << "Invalid Expression\n";
    }

    return 0;
}
