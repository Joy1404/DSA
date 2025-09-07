#include<bits/stdc++.h>
using namespace std;
//brute force approach
//time complexity O(n^2) where n is the number of weights
//space complexity O(1)
int shipWithinDaysBruteForce(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    for (int capacity = left; capacity <= right; capacity++) {
        int currentLoad = 0;
        int requiredDays = 1;
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = weight;
            } else {
                currentLoad += weight;
            }
        }
        if (requiredDays <= days) {
            return capacity;
        }
    }
    return right;
}
// Function to calculate the number of days required to ship all packages with a given capacity
// Helper function to determine if a given capacity can ship all packages within the specified days
int requiredDays(const vector<int>& weights, int capacity) {
    int days = 1;
    int currentLoad = 0;
    for (int weight : weights) {
        if (currentLoad + weight > capacity) {
            days++;
            currentLoad = weight;
        } else {
            currentLoad += weight;
        }
    }
    return days;
}
// Main function to find the minimum capacity to ship packages within the given days
//optimized using binary search
//time complexity O(n log m) where n is the number of weights and m is the range of possible capacities
//space complexity O(1)
int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (requiredDays(weights, mid) > days) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}