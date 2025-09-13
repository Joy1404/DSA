#include<bits/stdc++.h>
using namespace std;
// problem states that each row and each column is sorted in ascending order row is sorted from left to right and column j is sorted from top to bottom
//brute force approach
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
// binary search in a row
int bsearch(vector<int>& row, int target) {
    int low = 0, high = row.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (row[mid] == target) {
            return mid;
        } else if (row[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
//better
vector<int> searchMatrixBetter(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
   for(int i=0;i<m;i++){
       int index= bsearch(matrix[i],target);
       if(index!=-1){
           return {i,index};
       }
    }
    return {-1, -1};
}
// Time Complexity: O(m+n)
// Space Complexity: O(1)
vector<int> searchIn2DMatrixII(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return {-1, -1};
    int n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target) return {i, j};
        else if (matrix[i][j] > target) j--;
        else i++;
    }
    return {-1, -1};
}
int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    vector<int> result = searchMatrixBetter(matrix, target);
    if (result[0] != -1) {
        cout << "Element found at position: (" << result[0] << ", " << result[1] << ")\n";
    } else {
        cout << "Element not found in the matrix.\n";
    }
    return 0;
}