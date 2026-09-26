#include <iostream>

int prec(char c) {
    return (c == '+' || c == '-') ? 1 : (c == '*' || c == '/') ? 2 : (c == '^') ? 3 : 0;
}

void infixToPostfix(const char* s) {
    char stack[100];
    int top = -1, needSpace = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ' || s[i] == '\t') continue;

        if (s[i] >= '0' && s[i] <= '9') {
            if (needSpace) std::cout << " ";
            while (s[i] >= '0' && s[i] <= '9') std::cout << s[i++];
            needSpace = 1; i--;
        }
        else if (s[i] == '(') {
            stack[++top] = s[i];
        }
        else if (s[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                if (needSpace) std::cout << " ";
                std::cout << stack[top--];
                needSpace = 1;
            }
            if (top >= 0 && stack[top] == '(') top--;
        }
        else { // Operators
            while (top >= 0 && stack[top] != '(' && (prec(stack[top]) > prec(s[i]) ||
                  (prec(stack[top]) == prec(s[i]) && s[i] != '^'))) {
                if (needSpace) std::cout << " ";
                std::cout << stack[top--];
                needSpace = 1;
            }
            stack[++top] = s[i];
        }
    }
    while (top >= 0) {
        if (needSpace) std::cout << " ";
        std::cout << stack[top--];
    }
    std::cout << "\n";
}

int main() {
    infixToPostfix("3 + 4 * 2");
    infixToPostfix("(3 + 4) * 2");
    return 0;
}
