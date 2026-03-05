#include<bits/stdc++.h>
using namespace std;
// approach : we can use two nested loops to find the previous smaller element for each element in the array.
// time complexity : O(n^2) and space complexity : O(n)
vector<int>previousSmallerElement(vector<int>&arr){
    int n=arr.size();
    vector<int>pse(n,-1);
    for(int i =0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                pse[i]=arr[j];
                break;
            }
        }
    }
    return pse;
}
// approach : we can use stack to store the elements and we can pop the elements from the stack until we find the smaller element than the current element and we can push the current element to the stack after that.
// time complexity : O(n) and space complexity : O(n)
vector<int>previousSmallerElementOptimized(vector<int>&arr){
    int n=arr.size();
    vector<int>pse(n,-1);
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            pse[i]=-1;
        } else {
            pse[i]=s.top();
        }
        s.push(arr[i]);
    }
    return pse;
}
int main(){
    vector<int>arr={4,5,2,10};
    vector<int>pse=previousSmallerElementOptimized(arr);
    for(int i=0;i<pse.size();i++){
        cout<<pse[i]<<" ";
    }
    return 0;
}