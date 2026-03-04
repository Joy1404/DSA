#include<bits/stdc++.h>
using namespace std;
string prefixToPostfix(string s){
    stack<string> st;
    for(int i=s.size()-1;i>=0;i--){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            string op(1,s[i]);
            st.push(op);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp=op1+op2+s[i];
            st.push(temp);
        }
    }
    return st.top();
}
int main(){
    string prefix;
    cout << "Enter the prefix expression: ";
    cin >> prefix;
    string postfix = prefixToPostfix(prefix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}