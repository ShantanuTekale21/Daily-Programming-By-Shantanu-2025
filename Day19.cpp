#include <bits/stdc++.h>
using namespace std;
int evaluatePostfix(const string &expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = 0;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;
            st.push(result);
        }
        else {
            st.push(stoi(token));
        }
    }
    return st.top();
}
int main() {
    string expr;
    getline(cin, expr);
    cout << evaluatePostfix(expr) << endl;
    return 0;
}
