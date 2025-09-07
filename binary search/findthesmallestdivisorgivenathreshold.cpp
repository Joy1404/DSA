#include<bits/stdc++.h>
using namespace std;
// Function to find the smallest divisor such that the sum of the quotients is less than or equal to the threshold
// Time Complexity: O(n log m) where n is the number of elements in nums and m is the maximum element in nums
// Space Complexity: O(1)
int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int result = right;
    if (nums.size() > threshold) return -1; // Edge case: if there are more numbers than the threshold, it's impossible
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sum = 0;

        // Calculate the sum of the quotients
        for (int num : nums) {
            sum += (num + mid - 1) / mid; // Equivalent to ceil(num / mid)
        }

        // If the sum is within the threshold, try a smaller divisor
        if (sum <= threshold) {
            result = mid;
            right = mid - 1;
        } else { // Otherwise, try a larger divisor
            left = mid + 1;
        }
    }

    return result; // return left or result
}
//  brute force approach
// Time Complexity: O(n * m) where n is the number of elements in nums and m is the maximum element in nums
// Space Complexity: O(1)
int smallestDivisorBruteForce(vector<int>& nums, int threshold) {
    int maxNum = *max_element(nums.begin(), nums.end());

    for (int divisor = 1; divisor <= maxNum; ++divisor) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor; // Equivalent to ceil(num / divisor)
        }
        if (sum <= threshold) {
            return divisor;
        }
    }

    return maxNum; // In case no divisor is found, return the maximum number
}
int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << "Smallest Divisor: " << smallestDivisor(nums, threshold) << endl; // Output: 5
    return 0;
}