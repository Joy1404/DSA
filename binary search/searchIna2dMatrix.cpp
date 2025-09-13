#include<bits/stdc++.h>
using namespace std;
// brute force approach
// Time Complexity: O(m*n)
// Space Complexity: O(1)
bool searchMatrixBruteForce(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}
// better
bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
   for(int i=0;i<m;i++){
       if(target>=matrix[i][0] && target<=matrix[i][n-1]){
              int low=0,high=n-1;
              while(low<=high){
                int mid=low+(high-low)/2;
                if(matrix[i][mid]==target){
                     return true;
                }
                else if(matrix[i][mid]<target){
                     low=mid+1;
                }
                else{
                     high=mid-1;
                }
              }
       }
    }
    return false;
}
// Time Complexity: O(log(m*n))
// Space Complexity: O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = m * n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midValue = matrix[mid / n][mid % n];
        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    if (searchMatrix(matrix, target)) {
        cout << "Element found in the matrix.\n";
    } else {
        cout << "Element not found in the matrix.\n";
    }
    return 0;
}