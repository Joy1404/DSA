#include<bits/stdc++.h>
using namespace std;

// brutre force approach
// time complexity: O(n log n)
// space complexity: O(1)
int kthSmallestElementBruteForce(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}
// better approach using min-heap
// time complexity: O(n + k log n)
// space complexity: O(n)
int kthSmallestElementMinHeap(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // build the min-heap with all elements
    for (int num : arr) {
        minHeap.push(num);
    }
    // extract the minimum element k-1 times
    for (int i = 0; i < k - 1; i++) {
        minHeap.pop();
    }
    return minHeap.top();
}

// optimal approach using max-heap
// time complexity: O(n log k)
// space complexity: O(k)
// intuition: maintain a max-heap of size k, the top element will be the kth smallest element
int kthSmallestElement(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;
   // build the max-heap with the first k elements
    // for (int num : arr) {
    //     maxHeap.push(num);
    //     // maintain the size of the heap to be k
    //     if (maxHeap.size() > k) {
    //         maxHeap.pop();
    //     }
    // }
    for(int i=0;i<k;i++){
        maxHeap.push(arr[i]);
    }
    for(int i=k;i<arr.size();i++){
        if(arr[i]<maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top();
}
int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    cout << "Brute Force: " << kthSmallestElementBruteForce(arr, k) << endl;
    cout << "Min-Heap: " << kthSmallestElementMinHeap(arr, k) << endl;
    cout << "Optimal (Max-Heap): " << kthSmallestElement(arr, k) << endl;

    return 0;
}