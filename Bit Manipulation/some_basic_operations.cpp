#include<bits/stdc++.h>
using namespace std;
int main(){
  // swap 2 numbers
  int a = 5,b=10;
//    int temp =a;
//    a=b;
//    b =temp;
  a= a^b;
  b= a^b;// (a^b)^b = a
  a = a^b; //(a^b)^a = b
  cout<<a<<b<<endl;
  // check if a bit is set or not
  int n= 14;
  int i = 0;
  // method 1
  if((n & (1<<i))!=0) cout<< "set";
  else cout<<"not set";
  // method 2
  if(((n>>i)&1) ==0) cout<<" not set";
  else cout<<" set";
  // set the i-th bit
  n=(n | (1<<i));
  cout<<n<<endl;
  // clear the i-th bit
  n= n & (~(1<<i));
  cout<<n<<endl;
  // toggle the i-th bit
  n= n ^ (1<<i);
  // remove the right most set bit
  n= n & (n-1);
  // check if num is power of 2
  if((n&(n-1))==0) cout<<"power of 2";
  else cout<<" not power of 2";
  // counting set bits
  int num = 13;
  int cnt = 0;
//   while(num>0){
//    if(num%2==1) cnt++;
//    num=num/2;
//   }
//   while(num>0){
//    if(num&1) cnt++;
//    num>>=1;
//   }
  while(num>0){
   num= num & (num-1);
   cnt++;
  }
  cout<<cnt;
}