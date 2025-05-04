#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(string expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty() || !isMatching(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty(); // if stack is empty, all brackets matched
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr)) {
        cout << "Expression is balanced ✅\n";
    } else {
        cout << "Expression is not balanced ❌\n";
    }
    return 0;
}
