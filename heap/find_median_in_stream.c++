#include<bits/stdc++.h>
using namespace std;
// brute force approach
vector<double> findMedianBruteForce(vector<int>& nums) {
    vector<double> medians;
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        sort(temp.begin(), temp.end());
        int n = temp.size();
        if (n % 2 == 0) {
            medians.push_back((temp[n / 2 - 1] + temp[n / 2]) / 2.0);
        } else {
            medians.push_back(temp[n / 2]);
        }
    }
    return medians;
}

// optimal approach using heaps
vector<double> findMedianOptimal(vector<int>& nums) {
    vector<double> medians;
    priority_queue<int> maxHeap; // to store the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // to store the larger half
    // insert elements one by one
    for (int num : nums) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        // Balance the heaps
        // max heap can have at most one more element than min heap
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        // min heap size should not be greater than max heap size
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        // Calculate median
        if (maxHeap.size() == minHeap.size()) {
            medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
        } else {
            medians.push_back(maxHeap.top());
        }
    }
    return medians;
}
int main() {
    vector<int> nums = {5, 15, 1, 3,2,8};
    vector<double> medians = findMedianBruteForce(nums);
    for (double median : medians) {
        cout << median << " ";
    }
    cout << endl;
    medians = findMedianOptimal(nums);
    for (double median : medians) {
        cout << median << " ";
    }
    return 0;
}