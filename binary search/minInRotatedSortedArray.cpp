#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int ans = INT_MAX;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if( nums[left]<= nums[right]) {
            ans = min(ans, nums[left]);
            break;
        }
        if (nums[left] <= nums[mid]) {
            ans = min(ans, nums[left]);
            left = mid + 1;
        } else {
            ans = min(ans, nums[mid]);
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element in rotated sorted array: " << findMin(nums) << endl;
    return 0;
}