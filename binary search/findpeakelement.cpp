#include<bits/stdc++.h>
using namespace std;
// brute force
// O(n) time complexity
// space complexity O(1)
int findPeakElement(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        if((i==0 || arr[i-1]<arr[i]) && (i==arr.size()-1 || arr[i]>arr[i+1])){
            return i;
        }
    }
    return -1;
}
// Binary search
// O(log n) time complexity
// space complexity O(1)
//it is based on the idea that in a unimodal array, if you find a peak element, you can stop searching
//if the middle element is greater than its neighbors, then it is a peak element
//if the middle element is less than its left neighbor, then the peak element must be in the left half
//if the middle element is less than its right neighbor, then the peak element must be in the right half
int findPeakElementBinarySearch(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1;
    int high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        if (arr[mid] > arr[mid + 1]) {
            high = mid-1;
        }
        //  else if (arr[mid] > arr[mid - 1]) {
        //     low = mid + 1;
        // }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 3, 20, 4, 1};
    int peakIndex = findPeakElementBinarySearch(arr);
    if(peakIndex != -1){
        cout << "Peak element found at index: " << peakIndex << endl;
    } else {
        cout << "No peak element found." << endl;
    }
    return 0;
}