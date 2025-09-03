#include<bits/stdc++.h>
using namespace std;
// brute force
//time O(n)
int sqrtOfanNumber(int n){
    int ans=-1;
    for(int i=0;i<=n;i++){
        // if(i*i==n){
        //     return i;
        // }
        // if(i*i>n){
        //     return i-1;
        // }
        if(i*i<=n){
            ans=i;
        }else{
            break;
        }
    }
    return ans;
}
// optimized
int sqrtOfanNumberoptimal(int n){
    int s=1;
    int e=n;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        int square=mid*mid;
        if(square==n){
            return mid;
        }else if(square<n){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;   // return e    //if not found perfect square return the floor value 
}
int main(){
    int n;
    cin>>n;
    cout<<sqrtOfanNumber(n);
    cout<<sqrtOfanNumberoptimal(n);
    return 0;
}