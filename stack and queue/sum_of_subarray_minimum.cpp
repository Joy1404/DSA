#include<bits/stdc++.h>
using namespace std;
// Brute Force Approach at first we will find all the subarrays and then find the minimum of each subarray and add it to the sum. This approach will take O(n^2) time complexity.
int sumSubarrayMins(vector<int>&arr){
    int n = arr.size();
    int sum =0;
    for(int i=0;i<n;i++){
        int minm = arr[i];
        for(int j=i;j<n;j++){
            minm = min(minm,arr[j]);
            sum+=minm;
        }
    }
    return sum;
}
// Optimized Approach using Stack. We will use two stacks to find the next smaller element on the left and right side of each element in the array. Then we will calculate the contribution of each element to the sum using the formula: (i-left[i])*(right[i]-i)*arr[i], where left[i] is the index of the next smaller element on the left side of arr[i] and right[i] is the index of the next smaller element on the right side of arr[i]. This approach will take O(n) time complexity.
int sumSubarrayMinsOptimized(vector<int>&arr){
    int n = arr.size();
    stack<int>st;
    // left[i] will store the index of the previous smaller equal element on the left side of arr[i]
    // right[i] will store the index of the next smaller element on the right side of arr[i]
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
        sum+=(i-left[i])*(right[i]-i)*arr[i];
    }
    return sum;
}

int main(){
    vector<int>arr = {1,1};
    cout<<sumSubarrayMinsOptimized(arr);
    return 0;
}