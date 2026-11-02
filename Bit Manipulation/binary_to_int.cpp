#include<bits/stdc++.h>
using namespace std;
int binaryTodec(string x){
    int len = x.length();
    int p2=1,num=0;
    for(int i=len-1;i>=0;i--){
        if(x[i]=='1') num+=p2;
        p2*=2;
    }
    return num;
}
int main(){
    string x;
    cin>>x;
    int ans = binaryTodec(x);
    cout<<ans;
    return 0;
}
