#include<bits/stdc++.h>
using namespace std;

string prefixtoinfix(string s){
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
            string temp="("+op1+s[i]+op2+")";
            st.push(temp);
        }
    }
    return st.top();
}
int main(){
    string prefix;
    cout << "Enter the prefix expression: ";
    cin >> prefix;
    string infix = prefixtoinfix(prefix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}