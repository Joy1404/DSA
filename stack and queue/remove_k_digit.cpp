#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string &s , int k){
    int n = s.size();
    stack<char>st;
    for(int i=0;i<n;i++){
        while(!st.empty()&& k>0 && st.top()>s[i]){
            st.pop();
            k--;
        }
        st.push(s[i]);
}
while(!st.empty() && k>0){
    st.pop();
    k--;
}
if(st.empty()) return "0";
string ans = "";
while(!st.empty()){
    ans+=st.top();
    st.pop();
}
while(ans.size()>1 && ans.back()=='0') ans.pop_back();
reverse(ans.begin(), ans.end());
return ans;
}
int main(){
    string s = "1432219";
    int k = 3;
    cout << removeKdigits(s, k) << endl;
    return 0;
}