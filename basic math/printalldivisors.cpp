#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>s;
int n;
 cin>>n;
//  for(int i=1;i<=n;i++){
//     if(n%i==0){
//         cout<<i<<endl;
//     }
 for(int i=1;i*i<=n;i++){
    if(n%i==0){
        s.insert(i);
        if(i!=(n/i))
        s.insert(n/i);
    }
}
    for(auto it:s){
        cout<<it<<endl;
    }
 return 0;
}