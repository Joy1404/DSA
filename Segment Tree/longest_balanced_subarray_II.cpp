#include<bits/stdc++.h>
using namespace std;
// brute force
 int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        vector<int>cummusum(n,0);
        int maxl= 0;
        unordered_map<int,int> mp;
        for(int r =0;r<n;r++){
            int val = (nums[r]%2==0)? 1: -1;
            int prev = -1;
            if(mp.count(nums[r])){
                prev = mp[nums[r]];
            }
            if(prev!=-1){
                for(int l =0;l<=prev;l++){
                    cummusum[l]-= val;
                }
            }
            for(int l =0;l<=r;l++){
                cummusum[l]+=val;
            }
            for(int l =0;l<=r;l++){
                if(cummusum[l]==0){
                    maxl = max(maxl,r-l+1);
                    break;
                }
            }
            mp[nums[r]] = r;
        }
        return maxl;
    }
    // optimal

vector<int> segMin,segMax,lazy;
int n;
void propagate(int i , int l , int r){
    if(lazy[i]!=0){
        segMin[i]+=lazy[i];
        segMax[i]+=lazy[i];
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i] = 0;
    }
}
void updateRange(int start, int end,int  i, int  l, int r , int val){
    propagate(i,l,r);
    if(l> end || r <start) return;
    if(l>=start && r<=end){
        lazy[i]+=val;
        propagate(i,l,r);
        return;
    }
    int mid = (l+r)/2;
    updateRange(start,end, 2*i +1, l, mid,val);
    updateRange(start,end, 2*i +2, mid +1,r ,val);
    segMin[i] =  min(segMin[2* i +1],segMin[2*i+2]);
    segMax[i] =  max(segMax[2* i +1],segMax[2*i+2]);
}
int findleftmostzero(int i , int l , int r){
    propagate(i,l,r);
    if(segMin[i]>0 || segMax[i]<0) return -1;
    if(l==r) return l;
    int mid = l +(r-l)/2;
    int leftresult = findleftmostzero(2*i +1,l,mid);
    if(leftresult!=-1) return leftresult;
    return findleftmostzero(2*i+2,mid+1,r);
}

    int longestBalanced(vector<int>& nums) {
         n = nums.size();
         segMin.assign(4 * n ,0);
         segMax.assign(4 * n , 0);
         lazy.assign(4 * n , 0);
        vector<int>cummusum(n,0);
        int maxl= 0;
        unordered_map<int,int> mp;
        for(int r =0;r<n;r++){
            int val = (nums[r]%2==0)? 1: -1;
            int prev = -1;
            if(mp.count(nums[r])){
                prev = mp[nums[r]];
            }
            if(prev!=-1){
               updateRange(0,prev, 0 ,0, n-1,-val); 
            }
            updateRange(0,r,0,0,n-1,val);
           int l = findleftmostzero(0,0,n-1);
           if(l!=-1) maxl = max(maxl, r - l + 1);
            mp[nums[r]] = r;
        }
        return maxl;
    }

 int main(){
    vector<int> nums = {1,2,3,4,5,6};
    cout<<longestBalanced(nums);
 }