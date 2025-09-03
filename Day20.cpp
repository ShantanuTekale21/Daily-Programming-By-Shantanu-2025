#include <iostream>
#include <stack>
using namespace std;
void insertSorted(stack<int>& st, int element) {
    if (st.empty() || element < st.top()) {
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(temp);
}
void sortStack(stack<int>& st) {
    if (st.empty()) return;
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, temp);
}
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    cout << "Original Stack (top to bottom): ";
    printStack(st);
    sortStack(st);
    cout << "Sorted Stack (top to bottom): ";
    printStack(st);
    return 0;
}
