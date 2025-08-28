#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        // Check if the left half is sorted
        if (nums[left] <= nums[mid]) {
            // If the left half is sorted then check if the target is in the left half
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            // If the right half is sorted then check if the target is in the right half
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = search(nums, target);
    cout << "Index of " << target << ": " << result << endl;
    return 0;
}