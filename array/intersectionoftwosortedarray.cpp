#include <bits/stdc++.h>
using namespace std;
// Function to find the intersection of two sorted arrays
// brute force approach using two pointers and visited array
// Time Complexity: O(n * m) where n is the size of arr1 and m is the size of arr2
// Space Complexity: O(n) for the visited array

// vector<int> intersectionOfTwoSortedArrays(vector<int>& arr1, vector<int>& arr2) {
//     vector<int> result;
//     int n = arr1.size();
//     int m = arr2.size();
//     vector<bool> visited(n, false);

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (arr1[i] == arr2[j] && !visited[i]) {
//                 result.push_back(arr1[i]);
//                 visited[i] = true;
//                 break;
//             }
//             if( arr1[i] < arr2[j]) {
//                 break; // Since both arrays are sorted, no need to check further
//             }
//         }
//     }

//     return result;
// }

// Optimized approach using two pointers
// Time Complexity: O(n + m) where n is the size of arr1 and m is the size of arr2
// Space Complexity: O(1) for the pointers
vector<int> intersectionOfTwoSortedArrays(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> result;
    int n = arr1.size();
    int m = arr2.size();

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            // Both elements are equal
            result.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return result;
}
// Main function to test the intersection function
int main()
{
    vector<int> arr1 = {1, 2, 3, 3, 4, 5, 6};
    vector<int> arr2 = {2, 3, 3, 5, 7};

    vector<int> intersection = intersectionOfTwoSortedArrays(arr1, arr2);

    cout << "Intersection of the two sorted arrays: ";
    for (int num : intersection)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
