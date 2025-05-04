#include <iostream>
#include <stack>
#include <algorithm> // for reverse
using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert prefix to postfix
string prefixToPostfix(string prefix) {
    stack<string> s;

    // Process from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isOperator(ch)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = op1 + op2 + ch;
            s.push(temp);
        } else {
            s.push(string(1, ch)); // push operand as string
        }
    }

    return s.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression (e.g., *+AB-CD): ";
    cin >> prefix;

    string postfix = prefixToPostfix(prefix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
