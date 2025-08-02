#include<bits/stdc++.h>
using namespace std;
// Merge Sort Algorithm
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Stable Sort: Yes
// at first, we divide the array into two halves recursively until we reach arrays of size 1.
// Then we merge the two halves in a sorted manner.
// This process is repeated until the entire array is sorted.
// The merge function combines two sorted halves into a single sorted array.
// The mergeSort function recursively divides the array into halves and calls the merge function to sort and merge them.
void merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergeSort(vector<int>&arr,int low,int high){
    if(low==high){
        return;
    }
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void ms(vector<int>&arr,int n){
    mergeSort(arr,0,n-1);
}
int main(){
    vector<int>arr={5,4,3,2,1};
    int n=arr.size();
    ms(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}