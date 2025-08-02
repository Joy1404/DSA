#include<iostream>
using namespace std;
// bool f(int l,string &s,int r){
//     if(l>=r) return true;
//     if(s[l]!=s[r]){
//         return false;
//     }
//     f(l+1,s,r-1);
// }
bool f(int i,string &s,int n){
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]){
        return false;
    }
    f(i+1,s,n);
}
int main(){
string s="madam";

//  cout<<f(0,s,s.size()-1);
 cout<<f(0,s,s.size());

}