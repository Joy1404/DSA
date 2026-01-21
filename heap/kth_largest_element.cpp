#include<bits/stdc++.h>
using namespace std;
// brute force approach
// time complexity: O(n log n)
// space complexity: O(1)
int kthLargestElementBruteForce(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end(), greater<int>());
    return arr[k - 1];
}
// better approach using max-heap
// time complexity: O(n + k log n)
// space complexity: O(n)
int kthLargestElementMaxHeap(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;
    // build the max-heap with all elements
    for (int num : arr) {
        maxHeap.push(num);
    }
    // extract the maximum element k-1 times
    for (int i = 0; i < k - 1; i++) {
        maxHeap.pop();
    }
    return maxHeap.top();
}
// optimal approach using min-heap
// time complexity: O(n log k)
// space complexity: O(k)
// intuition: maintain a min-heap of size k, the top element will be the kth
// largest element
int kthLargestElement(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // build the min-heap with the first k elements
    for (int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    return minHeap.top();
}
int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    cout << "Brute Force: " << kthLargestElementBruteForce(arr, k) << endl;
    cout << "Max-Heap: " << kthLargestElementMaxHeap(arr, k) << endl;
    cout << "Optimal (Min-Heap): " << kthLargestElement(arr, k) << endl;

    return 0;
}