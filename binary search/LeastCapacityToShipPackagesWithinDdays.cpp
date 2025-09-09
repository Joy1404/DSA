#include<bits/stdc++.h>
using namespace std;
//optimal approach
//time complexity:O(nlogm) where n is the number of weights and m is the range of weights
//space complexity:O(1)
//function to calculate the number of days required to ship packages with given capacity
//if the number of days is less than or equal to the given days then we can ship the packages with the given capacity
//else we need to increase the capacity
int func(vector<int>& weights, int cap) {
    int days = 1;
    int current_weight = 0;
    for (int weight : weights) {
        if (current_weight + weight > cap) {
            days++;
            current_weight = weight;
        } else {
            current_weight += weight;
        }
    }
    return days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = low + (high - low) / 2;
      int  noofdays=func(weights, mid);
        if (noofdays <= days) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
// brute force approach
//time complexity:O(n^2) where n is the number of weights
//space complexity:O(1)
int shipWithinDaysBruteForce(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    for (int capacity = left; capacity <= right; capacity++) {
        int requireddays = func(weights, capacity);
        if (requireddays <= days) {
            return capacity;
        }
    }
    return -1; // This line should never be reached
}
int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << "Least capacity to ship packages within " << days << " days is: " << shipWithinDaysBruteForce(weights, days) << endl;
    return 0;
}