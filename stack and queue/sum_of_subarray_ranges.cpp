#include<bits/stdc++.h>
using namespace std;
// brute force approach will be to find all the subarrays and then find the maximum and minimum of each subarray and add the difference to the sum. This approach will take O(n^2) time complexity.
int sumSubarrayRanges(vector<int>& arr){
    int n = arr.size();
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int minVal = arr[i], maxVal = arr[i];
        for(int j = i+1; j < n; j++){
            minVal = min(minVal, arr[j]);
            maxVal = max(maxVal, arr[j]);
            sum += (maxVal - minVal);
        }
    }
    return sum;
}  
int sumSubarrayMinsOptimized(vector<int>&arr){
    int n = arr.size();
    stack<int>st;
    vector<int>left(n),right(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=(i-left[i])*(right[i]-i)*arr[i]; // contribution of each element to the sum of minimums of subarrays
    }
    return sum;
} 
int sumSubarrayMaxsOptimized(vector<int>&arr){
    int n = arr.size();
    stack<int>st;
    vector<int>left(n),right(n); 
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){ // for maximums we will pop until we find an element greater than equal to the current element
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i]){ // for maximums we will pop until we find an element greater than the current element
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=(i-left[i])*(right[i]-i)*arr[i]; // contribution of each element to the sum of maximums of subarrays
    }
    return sum;
}
int sumSubarrayRangesoptimized(vector<int>& arr){
    return sumSubarrayMaxsOptimized(arr) - sumSubarrayMinsOptimized(arr);
}
int main(){
    vector<int> arr = {1,4,3, 2};
    cout << sumSubarrayRangesoptimized(arr) << endl; 
    return 0;
}