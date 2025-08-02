#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int hash[26]={0}; //int hash[256]={0}; if not sure about capital or small or any character
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++; //has[s[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl; //hash[c]
    }
    return 0;
}
