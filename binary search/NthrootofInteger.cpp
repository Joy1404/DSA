#include<bits/stdc++.h>
using namespace std;
//Function to find nth root of an integer x
//If nth root is not an integer then return -1
//Time Complexity: O(x)^(1/n))
//Space Complexity: O(1)
int nthroot(int x,int n){
    for(int i=1;i<=x;i++){
        if(pow(i,n)==x){
            return i;
        }else if(pow(i,n)>x){
            return -1;
        }
    }
    return -1;
}
//Function to calculate mid^n
//to avoid overflow we will return 2 if mid^n>m
//return 1 if mid^n==m
//return 0 if mid^n<m
// time complexity: O(n)
// space complexity: O(1)
int func(int mid,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;

        if(ans>m){
            return 2; //to avoid overflow
        }
    }
    if(ans==m){
        return 1;
    return 0;
}
}
//optimal approach
//Time Complexity: O(logx)
//Space Complexity: O(1)
int nthrootOptimal(int n,int m){
    int low=1,high=m;
    while(low<=high){
        int mid=(low+high)/2;
        int midN=func(mid,n,m);
        if(midN==1){
            return mid;
        }else if(midN==0){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}