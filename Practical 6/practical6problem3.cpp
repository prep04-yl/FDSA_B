#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int priority(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> s;
    string postfix = "";

    for (char ch : exp) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && priority(s.top()) >= priority(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string expression;
    cin >> expression;

    cout << infixToPostfix(expression);

    return 0;
}


int main() {
    infixToPostfix("3 + 4 * 2");
    infixToPostfix("(3 + 4) * 2");
    return 0;
}
