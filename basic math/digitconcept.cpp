#include<iostream>
using namespace std;
int main(){
int n;
 cin>>n;
 while(n>0){
    int lastdigit=n%10;    
    cout<<"last digit is "<<lastdigit<<endl;
    n/=10;
 }
 return 0;
}
