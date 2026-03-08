#include<bits/stdc++.h>
using namespace std;

int maxAreaRectangle(vector<int>&arr){
    int n = arr.size();
    int maxi =0;
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty()&& arr[st.top()]> arr[i]){
            int height = arr[st.top()];
            st.pop();
          int width = st.empty() ? i : i-st.top()-1;
            maxi = max(maxi,height*width);
        }
        st.push(i);
    }
    while(!st.empty()){
        int height = arr[st.top()];
        st.pop();
        int nse = n;
        int pse = st.empty() ? -1 : st.top();
        int width = nse-pse-1;
        maxi = max(maxi,height*width);
    }
    return maxi;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if(n==0) return 0;
    int m = matrix[0].size();
   vector<vector<int>>psum(n,vector<int>(m,0));
    int maxi =0;
   for(int j =0;j<m;j++){
    int sum =0;
    for(int i =0;i<n;i++){
        if(matrix[i][j]=='1') sum++;
        else sum =0;
        psum[i][j] = sum;
    }
   }
   for(int i=0;i<n;i++){
    maxi = max(maxi,maxAreaRectangle(psum[i]));
   }
   return maxi;
}
int main(){
    vector<vector<char>>matrix = {{'1','0','1','0','0'},
                                  {'1','0','1','1','1'},
                                  {'1','1','1','1','1'},
                                  {'1','0','0','1','0'}};
    cout<<maximalRectangle(matrix)<<endl;
}