#include<iostream>
#include<math.h>
using namespace std;
int main(){
int n,count;
 cin>>n;
 if(n==0) count=1;
//  while(n>0){
//     int lastdigit=n%10;    
//     cout<<"last digit is "<<lastdigit<<endl;
//     n/=10;
//     count++;
//  }
count=log10(n)+1;

 cout<<count;
 return 0;
}
