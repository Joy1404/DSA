#include<bits/stdc++.h>
using namespace std;
// Function to find the length of the longest subarray with sum equal to k
//brute force approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int longestSubarrayWithSumK(int arr[], int n, int k) {
    int maxLength = 0;

    // Iterate through all possible subarrays
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            if (currentSum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}
// Optimized approach using HashMap for positive and negative integers
// This approach uses a HashMap to store the cumulative sum and its first occurrence index.
// Time Complexity: O(n)
// Space Complexity: O(n)
int longestSubarrayWithSumKOptimized(int arr[], int n, int k) {
    unordered_map<int, int> sumIndexMap;
    int maxLength = 0;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        // Check if the current sum is equal to k
        if (currentSum == k) {
            maxLength = max(maxLength, i + 1); // Update maxLength if the subarray starts from index 0
        }
        int rem=currentSum-k; 

        // If currentSum - k exists in the map, update maxLength
        if (sumIndexMap.find(rem) != sumIndexMap.end()) {
            int length = i - sumIndexMap[rem];
            maxLength = max(maxLength, length);
        }

        // Store the first occurrence of the current sum
        if (sumIndexMap.find(currentSum) == sumIndexMap.end()) {
            sumIndexMap[currentSum] = i;
        }
    }
    return maxLength;
}
//optimal for positive integers using two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
int longestSubarrayWithSumKOptimizedTwoPointers(int arr[], int n, int k) {
    int maxLength = 0;
    int left = 0,right=0, currentSum = 0;
    int sum=arr[0];
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxLength=max(maxLength,right-left+1);
        }
        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    return maxLength;
}
// Driver code
int main() {
    int arr[] = {1, -1, 5, -2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // Using brute force approach
    cout << "Length of longest subarray with sum " << k << " (Brute Force): "
         << longestSubarrayWithSumK(arr, n, k) << endl;

    // Using optimized approach
    cout << "Length of longest subarray with sum " << k << " (Optimized): "
         << longestSubarrayWithSumKOptimized(arr, n, k) << endl;

    return 0;
}