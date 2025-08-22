#include<bits/stdc++.h>
using namespace std;
// brute force
// time complexity : O(n*n)
// space complexity : O(1)
int countInversion(vector<int>& arr){
    int count = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}
// optimal 
// time complexity : O(n log n)
// space complexity : O(n)
// Function to merge two halves and count inversions
// int counter = 0;
int merge(vector<int>& arr, int left, int mid, int right) {
    int counter = 0;
    int i = left;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            counter += (mid - i + 1);  // Count inversions
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
    return counter;
}

// Function to implement merge sort and count inversions
int mergeSort(vector<int>& arr, int left, int right) {
    int cnt =0;
    if (left >= right) return cnt;
    int mid = (left + right) / 2;
    cnt += mergeSort(arr, left, mid);
    cnt += mergeSort(arr, mid + 1, right);
    cnt += merge(arr, left, mid, right);
    return cnt;
}

// Function to count inversions in the array
int countInversions(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << countInversions(arr) << endl;
    return 0;
}