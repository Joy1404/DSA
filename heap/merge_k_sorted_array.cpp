#include<bits/stdc++.h>
using namespace std;
// time complexity:O(k2 log(k)) where k is the number of arrays and l is the average length of each array
// space complexity: O(1) for the heap sort and O(k) for the merging process
// brute force approach: push all elements into a single array and then sort the array
vector<int> mergeKSortedArraysbrute(vector<vector<int>>& arr, int k) {
   vector<int> ans;
   for(int i=0;i<k;i++){
    for(int j=0;j<k;j++){
        ans.push_back(arr[i][j]);
    }
}
// use merge sort or heap sort to sort the array
    sort(ans.begin(),ans.end());
    
   return ans;
}
// time complexity:O(k2 log(k)) where k is the number of arrays and l is the average length of each array
// s.c:o(k2)
// push all elements into a min heap and then extract them to get a sorted array
   vector<int> mergeArraysbetter(vector<vector<int>> &arr) {
        // Code here
        int k = arr.size();
        int k = arr[0].size();
         vector<int> ans;
         priority_queue<int,vector<int>,greater<int>>pq;
   for(int i=0;i<k;i++){
    for(int j=0;j<k;j++){
       pq.push(arr[i][j]);
    }
}
    while(!pq.empty()){
        int temp=pq.top();
        pq.pop();
        ans.push_back(temp);
    }
    
   return ans;
}
// time complexity:O(k2 log(k)) where k is the number of arrays and l is the average length of each array
// s.c O(k)
vector<int>mergeKSortedArraysminheap(vector<vector<int>>&arr,int k){
    vector<int>ans;
    // min heap to store the elements
    priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>>>, greater< pair<int,pair<int,int>>> > minHeap;
    // push the first element of each array into the min heap
    for(int i=0;i<k;i++){
        minHeap.push({arr[i][0],{i,0}});
    }
    // extract the minimum element from the min heap and push it into the answer array
    while(!minHeap.empty()){
        auto temp = minHeap.top();
        minHeap.pop();
        int element = temp.first;
        int row = temp.second.first;
        int col = temp.second.second;
        ans.push_back(element);
        // push the next element of the same array into the min heap
        if(col+1<k){
            minHeap.push({arr[row][col+1],{row,col+1}});
        }
    }
    return ans;
}
int main(){
    int k=3;
    vector<vector<int>> arr = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };
    vector<int> mergedArray = mergeKSortedArraysbrute(arr, k);
    for(int num : mergedArray){
        cout << num << " ";
    }
    return 0;
}