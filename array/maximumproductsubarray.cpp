#include<bits/stdc++.h>
using namespace std;
// brute force
int maxproductsubarray(vector<int>nums){
    int n = nums.size();
    int mx=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int product = 1;
            for(int k=i;k<=j;k++){
                product *= nums[k];
            }
            mx = max(mx, product);
        }
    }
    return mx;
}
// better 
int maxproductsubarray(vector<int>nums){
    int n = nums.size();
    int mx=0;
    for(int i=0;i<n;i++){
        int product = 1;
        for(int j=i;j<n;j++){
            product *= nums[j];
            mx = max(mx, product);
        }
    }
    return mx;
}

// optimal
int maxproductsubarray(vector<int>nums){
    int pre=1,suff=1,mx=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre *= nums[i];
        suff *= nums[nums.size()-1-i];
        mx = max(mx,max(pre,suff));
    }
    return mx;
}
int main(){
    vector<int>nums = {2,3,-2,4};
    cout<<maxproductsubarray(nums);
    return 0;
}