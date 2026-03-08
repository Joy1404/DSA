#include<bits/stdc++.h>
using namespace std;
vector<int>findpse(vector<int>& arr){
    int n=arr.size();
    vector<int>pse(n,-1);
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            pse[i]=-1;
        } else {
            pse[i]=s.top();
        }
        s.push(i);
    }
    return pse;
}
vector<int>findnse(vector<int>& arr){
    int n=arr.size();
    vector<int>nse(n);
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            nse[i]=n;
        } else {
            nse[i]=s.top();
        }
        s.push(i);
    }
    return nse;
}
// optimized approach using stack. We will use a stack to keep track of the indices of the elements in the array. We will iterate through the array and for each element we will pop the elements from the stack until we find an element which is smaller than the current element. The area of the rectangle formed by the element at index i will be (i-pse[i]-1)*arr[st.top()], where i is the index of the next smaller element on the right side of arr[i] and pse[i] is the index of the previous smaller element on the left side of arr[i]. We will keep track of the maximum area while iterating through the array. This approach will take O(n) time complexity.
int maxAreaRectangle(vector<int>&arr){
    int n = arr.size();
    int maxi =0;
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty()&& arr[st.top()]> arr[i]){
            int height = arr[st.top()];
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            // int width = st.empty() ? i : i-st.top()-1;
            int width = nse-pse-1;
            maxi = max(maxi,height*width);
        }
        st.push(i);
    }
    while(!st.empty()){
        int height = arr[st.top()];
        st.pop();
        int nse = n;
        int pse = st.empty() ? -1 : st.top();
        // int width = st.empty() ? n : n-st.top()-1;
        int width = nse-pse-1;
        maxi = max(maxi,height*width);
    }
    return maxi;
}
// To find the largest rectangle in histogram we will use the next smaller element and previous smaller element of each element in the array. The area of the rectangle formed by the element at index i will be (nse[i]-pse[i]-1)*arr[i], where nse[i] is the index of the next smaller element on the right side of arr[i] and pse[i] is the index of the previous smaller element on the left side of arr[i]. We will iterate through the array and calculate the area for each element and keep track of the maximum area. This approach will take O(n) time complexity.
int maxRectangleArea(vector<int>&arr){
    int n = arr.size();
    int maxi =0;
    vector<int>nse = findnse(arr);
    vector<int>pse = findpse(arr);
    for(int  i= 0;i<n;i++){
        maxi = max(maxi,((nse[i]-pse[i]-1)*arr[i]));
    }
    return maxi;
}
int main(){
    vector<int>arr={2,1,5,6,2,3};
    cout<<maxAreaRectangle(arr);
    return 0;
}