#include <bits/stdc++.h>
using namespace std;
// Function to find the k-th smallest element in a sorted matrix row-wise and column-wise
// brute force
// time complexity: O(n^2 log(n^2)) space complexity: O(n^2)
// approach: flatten the matrix into a single array, sort the array, and return the k-th smallest element.
int kthSmallestbrute(vector<vector<int>> &matrix, int k)
{
    vector<int> elements;
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            elements.push_back(elem);
        }
    }
    sort(elements.begin(), elements.end());
    return elements[k - 1];
}
// better approach using min-heap
// time complexity: O(n^2 +klog(n^2)) space complexity: O(k)
// approach: insert all elements into a min-heap and extract the minimum k times.
int kthSmallestbetter(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            minHeap.push(matrix[i][j]);
        }
    }
    int ans = -1;
    for (int i = 0; i < k; i++)
    {
        ans = minHeap.top();
        minHeap.pop();
    }
    return ans;
}
// int kthSmallestoptimised(vector<vector<int>>&matrix,int k){
// int n=matrix.size();
// priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
// for(int j=0;j<n;j++){
//     minHeap.push({matrix[0][j],{0,j}});
// }
// int ans=-1;
// for(int i=0;i<k;i++){
//     auto it=minHeap.top();
//     minHeap.pop();
//     ans=it.first;
//     int r=it.second.first;
//     int c=it.second.second;
//     if(r+1<n){
//         minHeap.push(make_pair(matrix[r+1][c],make_pair(r+1,c)));
//     }
// return ans;
// }
// Optimized approach using min-heap
// time complexity: O(k log n) space complexity: O(n)
// approach: only insert the first element of each row into the min-heap, then extract the minimum k times, and for each extracted element, insert the next element from the same row into the heap.
int kthSmallestoptimised1(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < n; i++)
        temp.push_back({mat[i][0], make_pair(i, 0)});
    // create min heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());
    // value,row,col
    int ans;
    pair<int, pair<int, int>> element;
    int i, j;
    while (k--)
    {
        element = p.top();
        p.pop();
        ans = element.first;       // val
        i = element.second.first;  // row
        j = element.second.second; // col
        if (j + 1 < n)
            p.push({mat[i][j + 1], {i, j + 1}});
    }
    return ans;
}
// Further Optimized approach using min-heap
// time complexity: O(k log n) space complexity: O(n)
// approach: similar to the previous approach, but we mark the elements that have been added to the heap by setting them to 0 in the matrix itself to avoid using extra space for a visited array. we add the first element of the matrix to the heap, and for each extracted element, we add the next element in the same row and the next element in the same column to the heap if they haven't been added before.
int kthSmallestoptimised2(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;

    p.push(make_pair(mat[0][0], make_pair(0, 0)));
    mat[0][0] = 0;

    pair<int, pair<int, int>> Element;
    int row, col, ans;

    while (k--)
    {
        Element = p.top();
        p.pop();
        ans = Element.first;
        row = Element.second.first;
        col = Element.second.second;

        if (col + 1 < n && mat[row][col + 1])
        {
            p.push(make_pair(mat[row][col + 1], make_pair(row, col + 1)));
            mat[row][col + 1] = 0;
        }

        if (row + 1 < n && mat[row + 1][col])
        {
            p.push(make_pair(mat[row + 1][col], make_pair(row + 1, col)));
            mat[row + 1][col] = 0;
        }
    }
    return ans;
}

//count function to check whether the Kth element  lies left half and right half
// time complexity: O(n) space complexity: O(1)
int countLessEqual(vector<vector<int>>& mat, int N, int mid) {
    int count = 0, row = N - 1, col = 0;

    while (row >= 0 && col < N) {
        if (mat[row][col] <= mid) {
            count += (row + 1);  // Add all elements in this column
            col++;  // Move right
        } else {
            row--;  // Move up
        }
    }
    return count;
}
// Binary Search approach
// time complexity: O(n log(max-min)) space complexity: O(1)
// approach: use binary search on the value range of the matrix. For each mid value, count how many elements are less than or equal to mid. If the count is greater than or equal to k, search in the left half; otherwise, search in the right half.
int kthSmallest(vector<vector<int>>& mat,  int k)
{
    int n = mat.size();
  int low = mat[0][0], high = mat[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = countLessEqual(mat, n, mid);

        if (count >= k) {
            high = mid;  // Search left
        } else {
            low = mid + 1;  // Search right
        }
    }
    return low;  // Kth smallest element
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}};
    int k = 8;
    cout << "K-th smallest element (Brute Force): " << kthSmallestbrute(matrix, k) << endl;
    cout << "K-th smallest element (Better): " << kthSmallestbetter(matrix, k) << endl;
    cout << "K-th smallest element (Optimized): " << kthSmallestoptimised1(matrix, k) << endl;
    cout << "K-th smallest element (Binary Search): " << kthSmallest(matrix, k) << endl;
    cout << "K-th smallest element (Optimized 2): " << kthSmallestoptimised2(matrix, k) << endl;
    return 0;
}