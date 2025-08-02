#include<iostream>
using namespace std;
int main(){
int n,armnum=0;
 cin>>n;
 int num=n;
 while(n>0){
    int l=n%10;    
    armnum+=(l*l*l);
    n/=10;
 }
 cout<<(num==armnum);
 return 0;
}
