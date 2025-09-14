#include<bits/stdc++.h>
using namespace std;
// brute force approach
int median(vector<vector<int>> &matrix, int r, int c) {
    vector<int> arr;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr.push_back(matrix[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    int n = arr.size();
    if(n%2==0){
        return (arr[n/2]+arr[(n/2)-1])/2;
    }
    return arr[n/2];
}
// optimal approach
int countSmallerThanEqualToMid(vector<vector<int>> &matrix, int mid, int r, int c) {
    int count = 0;
    for(int i=0;i<r;i++){
        count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    }
    return count;
}
int median(vector<vector<int>> &matrix, int r, int c) {
    int low=INT32_MAX, high=INT32_MIN;
    for(int i=0;i<r;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][c-1]);
    }
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(countSmallerThanEqualToMid(matrix, mid, r, c) <= (r * c) / 2) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> matrix(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<median(matrix,r,c);
    return 0;
}