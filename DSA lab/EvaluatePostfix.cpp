#include <iostream>
#include <stack>
#include <cctype> // for isdigit
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expr) {
    stack<int> s;

    for (char ch : expr) {
        if (isdigit(ch)) {
            // Convert char to int and push to stack
            s.push(ch - '0');
        } else {
            // Pop top two values for operation
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        cout << "Error: Division by zero\n";
                        return -1;
                    }
                    s.push(val1 / val2); 
                    break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
        }
    }
    return s.top(); // Final result
}

int main() {
    string expr;
    cout << "Enter postfix expression (e.g., 231*+9-): ";
    cin >> expr;

    int result = evaluatePostfix(expr);
    cout << "Result: " << result << endl;

    return 0;
}
