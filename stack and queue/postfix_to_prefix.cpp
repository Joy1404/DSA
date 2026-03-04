#include<bits/stdc++.h>
using namespace std;

string postfixtoprefix(string s){
    stack<string> st;
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            string op(1,s[i]);
            st.push(op);
        }
        else{
            string op2=st.top();
            st.pop();
            string op1=st.top();
            st.pop();
            string temp=s[i]+op1+op2;
            st.push(temp);
        }
    }
    return st.top();
}
int main(){
    string postfix;
    cout << "Enter the postfix expression: ";
    cin >> postfix;
    string prefix = postfixtoprefix(postfix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}