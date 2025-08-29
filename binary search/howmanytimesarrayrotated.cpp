#include<bits/stdc++.h>
using namespace std;

int noofrotations(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int minIndex = -1;
    int ans=INT32_MAX;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if( nums[left]<= nums[right]) {
           if(nums[left]<ans){
               minIndex=left;
               ans=nums[left];
           }
            break;
        }
        if (nums[left] <= nums[mid]) {
            if(nums[left]<ans){
                minIndex=left;
                ans=nums[left];
            }
            left = mid + 1;
        } else {
            right = mid - 1;
            if(nums[mid]<ans){
                minIndex=mid;
                ans=nums[mid];
            }
        }
    }
    return minIndex;
}
int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Number of rotations in the array: " << noofrotations(nums) << endl;
    return 0;
}