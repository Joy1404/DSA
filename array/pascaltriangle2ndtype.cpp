#include<iostream>
using namespace std;
//brute force
int ncr(int n, int r)
{
   long long res = 1;
   for (int i = 0; i < r; i++)
   {
       res = res * (n - i);
       res = res / (i + 1);
   }
   return res;
}
int main(){
    int n;
    cout<<"Enter the number of row for Pascal's Triangle: ";
    cin>>n;
    for(int i=1;i<=n;i++){
            cout<<ncr(n-1,i-1)<<" ";
    }
}