#include<bits/stdc++.h>
using namespace std;

// approach : we will use two loops to find the maximum element in the sliding window of size k. 
// time complexity : O(n*k) where n is the size of the array and k is the size of the sliding window.
// space complexity : O(1) as we are not using any extra space to store the maximum element in the sliding window. except the answer vector which is of size n-k+1.
vector<int>maxslidingwindow(vector<int>& arr , int k ){
   vector<int> ans;
   for(int i=0;i<=arr.size()-k;i++){
       int max = arr[i];
       for(int j=i+1;j<i+k;j++){
           if(arr[j]>max){
               max = arr[j];
           }
       }
       ans.push_back(max);
   }
   return ans;
}
vector<int> maxslidingwindow1(vector<int>& arr , int k ){
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<arr.size();i++){
        while(!dq.empty() && dq.front()<=i-k){ // we are checking if the front element of the deque is out of the sliding window or not. if it is out of the sliding window then we will pop it from the front of the deque.
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<=arr[i]){ // we are checking if the back element of the deque is less than or equal to the current element or not. if it is less than or equal to the current element then we will pop it from the back of the deque.
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){ // we are checking if the current index is greater than or equal to k-1 or not. if it is greater than or equal to k-1 then we will push the front element of the deque in the answer vector as the front element of the deque is the maximum element in the sliding window of size k.
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxslidingwindow(arr,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}