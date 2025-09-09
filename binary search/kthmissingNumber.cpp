#include<bits/stdc++.h>
using namespace std;
//brute force approach
//time complexity:O(n) where n is the number of elements in the array
//space complexity:O(1)
//if the kth missing number is less than the last element of the array
//then we can iterate through the array and check if the current element is less than or equal to k
//if it is then we increment k by 1
//if it is not then we break the loop and return k
//if the kth missing number is greater than the last element of the array
//then we can return the last element of the array + (k - number of elements in the array)
int missingElement(vector<int>& nums,int k){
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]<=k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}
//optimized approach
//time complexity:O(logn) where n is the number of elements in the array
//space complexity:O(1)
//we can use binary search to find the kth missing number
//we can calculate the number of missing elements before the mid index
//if the number of missing elements is less than k then we can move to the right half of the array
//if the number of missing elements is greater than or equal to k then we can move to the left half of the array
//at the end of the loop low will be pointing to the index where the kth missing number is located
//we can return low + k as the kth missing number
int missingElement2(vector<int>& nums,int k){
    int n=nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=nums[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low+k; // return high+k+1;
}
int main(){
    vector<int> nums={2,3,4,7,11};
    int k=5;
    cout<<missingElement(nums,k)<<endl; //brute force approach
    cout<<missingElement2(nums,k)<<endl; //optimized approach
    return 0;
}