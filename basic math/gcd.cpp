#include<iostream>
using namespace std;
int main(){
    int n1,n2,gcd;
    cin>>n1>>n2;
    // for(int i=1;i<=min(n1,n2);i++){
    // for(int i=min(n1,n2);i>=1;i--){
    //     if(n1%i==0 && n2%i==0){
    //         gcd=i;
    //         break;
    //     }
    // }
    while(n1>0 && n2>0){
        if(n1>n2) n1=n1%n2;
        else n2=n2%n1;
    }
    if(n1==0) gcd=n2;
    else gcd=n1;
    cout<<gcd;
    return 0;
    //tc-o(log(min(a,b))
}