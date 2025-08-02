#include<iostream>
using namespace std;
int f(int num,int a[],int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==num){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int a[6]={1,2,1,2,4,5};
    cout<<f(1,a,6);
    cout<<f(4,a,6);
    cout<<f(2,a,6);
}