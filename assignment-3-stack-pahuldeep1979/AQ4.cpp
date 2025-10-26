#include <iostream>
using namespace std;

#define MAX 100

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isRightAssociative(char op) {
    return op == '^';
}

int main() {
    char infix[MAX], postfix[MAX], stack[MAX];
    int top = -1;
    int j = 0;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1) top--;  // pop '('
        }
        else if (isOperator(c)) {
            while (top != -1 && stack[top] != '(') {
                char topOp = stack[top];
                int precTop = precedence(topOp);
                int precCur = precedence(c);

                // For right-associative ^, don't pop if same precedence
                if ((precTop > precCur) || (precTop == precCur && !isRightAssociative(c))) {
                    postfix[j++] = stack[top--];
                } else {
                    break;
                }
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

