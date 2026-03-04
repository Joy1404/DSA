#include<bits/stdc++.h>
using namespace std;

int precedence(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}
string infixToPrefix(string infix){
    stack<char> s;
    string prefix;
    reverse(infix.begin(), infix.end());
    for(int i=0; i<infix.length(); i++){
        char c = infix[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            prefix += c;
        }
        else if(c == ')'){ // since we reversed the infix, we need to check for ')' instead of '('
            s.push(c);
        }
        else if(c == '('){ // since we reversed the infix, we need to check for '(' instead of ')'
            while(!s.empty() && s.top() != ')'){
                prefix += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        }
        else{
            if(c == '^'){
                while(!s.empty() && precedence(s.top()) >= precedence(c)){
                    prefix += s.top();
                    s.pop();
                }
            }
            else{
            while(!s.empty() && precedence(s.top()) > precedence(c)){
                prefix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
}
    while(!s.empty()){
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main(){
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}