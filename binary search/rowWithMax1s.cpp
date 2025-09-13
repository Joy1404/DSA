#include<bits/stdc++.h>
using namespace std;
//optimal approach
// time complexity: O(n + logm)
// space complexity: O(1)
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1,ans=arr.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
    int rowIndex = -1; // Initialize to -1 to indicate no row found yet
    int maxCount = 0; // Initialize maxCount to keep track of maximum 1s

    for (int i = 0; i < n; i++) {
        int cnt_max = 0; // Count of 1s in the current row
       int index=-1;
         int cnt_ones=m - lowerBound(arr[i],1);
        if (cnt_ones > maxCount) {
            maxCount = cnt_ones;
            rowIndex = i;
        }
    }

    return rowIndex; // Return the index of the row with maximum 1s
}

// brute force approach
// time complexity: O(n*m)
// space complexity: O(1)
int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
    int rowIndex = -1; // Initialize to -1 to indicate no row found yet
    int maxCount = 0; // Initialize maxCount to keep track of maximum 1s
  

    for (int i = 0; i < n; i++) {
        int cnt_row = 0; // Count of 1s in the current row
        for (int j = 0; j < m; j++) {
           cnt_row+=arr[i][j];
        }
        if (cnt_row > maxCount) {
            maxCount = cnt_row;
            rowIndex = i;
        }
    }

    return rowIndex; // Return the index of the row with maximum 1s
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout << rowWithMax1s(arr, n, m) << endl;
    return 0;
}