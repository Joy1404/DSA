#include<bits/stdc++.h>
using namespace std;
// approach : we can use two nested loops to find the next greater element for each element in the array. here we are using modulo operator to get the index of the next element in the array and we are iterating the array twice to get the next greater element for the last element in the array.
// time complexity : O(n^2) and space complexity : O(n)
vector<int>NextGreaterElement(vector<int>&arr){
    int n=arr.size();
    vector<int>nge(n,-1);
    for(int i=0;i<n;i++){
        for(int j=(i+1)%n;j!=i;j=(j+1)%n){ // for(int j = i+1;j<i+n-1;j++)
            if(arr[j]>arr[i]){
                nge[i]=arr[j];
                break;
            }
        }
    }
    return nge;
}
// approach : we can use stack to store the elements and we can pop the elements from the stack until we find the greater element than the current element and we can push the current element to the stack after that.here we are using modulo operator to get the index of the next element in the array and we are iterating the array twice to get the next greater element for the last element in the array.
// time complexity : O(n) and space complexity : O(n)
vector<int>NextGreaterElementOptimized(vector<int>&arr){
    int n=arr.size();
    vector<int>nge(n,-1);
    stack<int>s;
    for(int i=2*n-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i%n]){
            s.pop();
        }
       if(i<n){
        nge[i]=s.empty()?-1:s.top(); 
       }
        s.push(arr[i%n]);
    }
    return nge;
}
int main(){
    vector<int>arr={4,5,12,2,10};
    vector<int>nge=NextGreaterElementOptimized(arr);
    for(int i=0;i<nge.size();i++){
        cout<<nge[i]<<" ";
    }
    return 0;
}