#include<bits/stdc++.h>
using namespace std;
// approach : we can use two nested loops to find the next greater element for each element in the array.
// time complexity : O(n^2) and space complexity : O(n)
vector<int> nextGreaterElement(vector<int>&arr){
    int n=arr.size();
    vector<int>nge(n,-1);
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                nge[i]=arr[j];
                break;
            }
        }
    }
    return nge;
}
// approach : we can use stack to store the elements and we can pop the elements from the stack until we find the greater element than the current element and we can push the current element to the stack after that.
// time complexity : O(n) and space complexity : O(n)
vector<int> nextGreaterElementOptimized(vector<int>&arr){
    int n=arr.size();
    vector<int>nge(n,-1);
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            nge[i]=-1;
        } else {
            nge[i]=s.top();
        }
        s.push(arr[i]);
    }
    return nge;
}
int main(){
    vector<int>arr={4,5,2,10};
    vector<int>nge=nextGreaterElementOptimized(arr);
    for(int i=0;i<nge.size();i++){
        cout<<nge[i]<<" ";
    }
    return 0;
}