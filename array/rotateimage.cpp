#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Function to rotate the image represented by a 2D matrix by 90 degrees clockwise
// brute force approach
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
void rotateImage(vector<vector<int>>& matrix) {
    int n = matrix.size();
     vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = rotated;
}
//optimal approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
void rotateImageOptimal(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // First, transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Then, reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    // if rotate in anti-clockwise direction
    // First, transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Then, reverse each column
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n / 2; ++i) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    rotateImage(matrix);
    
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}