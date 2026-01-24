#include<bits/stdc++.h>
using namespace std;
// problem statement: merge two binary max heaps
// approach: it first merges two arrays and then converts the merged array
// then converts the merged array into a max heap by applying heapify from bottom to top
// it first merges two arrays and then converts the merged array into a max heap
 void heapify(vector<int>&ans,int i , int n){
      int largest =i;
      int left = 2*i+1;
      int right = 2*i+2;
      if(left<n && ans[left]>ans[largest]) largest = left;
      if(right<n && ans[right]>ans[largest]) largest = right;
      if(largest!=i){
          swap(ans[i],ans[largest]);
          heapify(ans,largest,n);
      }
  }
  // main function to merge two max heaps
  // time complexity: O(n+m)
  // space complexity: O(1)
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       vector<int>ans;
        for(int num : a) ans.push_back(num);
        for(int num : b) ans.push_back(num);
        // step down to max heap
        n = ans.size();
        for(int i=n/2 -1 ;i>=0;i--){
            // this function will ensure max heap property
            heapify(ans,i,n);
        }
        return ans;
    }
int main(){
    vector<int> a = {10,5,6,2};
    vector<int> b = {12,7,9};
    vector<int> mergedHeap = mergeHeaps(a,b,a.size(),b.size());
    cout<<"Merged Max Heap: ";
    for(int num : mergedHeap){
        cout<<num<<" ";
    }
    return 0;
}