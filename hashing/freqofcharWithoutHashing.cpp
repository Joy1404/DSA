#include<iostream>
using namespace std;
int f(char c ,string s){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==c){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    string s="abcdabegc";
    
    cout<<f('a',s);
    cout<<f('c',s);
    cout<<f('z',s);
}