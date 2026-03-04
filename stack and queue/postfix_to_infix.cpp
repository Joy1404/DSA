#include<bits/stdc++.h>
using namespace std;

string postfixToInfix(string postfix){
    stack<string> s;
    for(int i=0; i<postfix.length(); i++){
        char c = postfix[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            s.push(string(1, c));
        }
        else{
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string temp = "(" + op1 + c + op2 + ")";
            s.push(temp);
        }
    }
    return s.top();
}
int main(){
    string postfix;
    cout << "Enter the postfix expression: ";
    cin >> postfix;
    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}