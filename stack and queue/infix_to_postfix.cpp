#include<bits/stdc++.h>
using namespace std;

int precedence(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string ans = "";
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            ans += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // Pop the '(' from the stack 
        }
        else{
            while(!st.empty() && precedence(st.top()) >= precedence(c)){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}