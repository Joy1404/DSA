#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            //  if ((c == ')' && top == '(') ||
            //     (c == '}' && top == '{') ||
            //     (c == ']' && top == '[')){
            //     continue;
            //     }
            //     else{
            //         return false;
            //     }

        }
    }
    return st.empty();
}
int main() {
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    if (isBalanced(s)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }
    return 0;
}