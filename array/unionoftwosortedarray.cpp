#include<bits/stdc++.h>
using namespace std;
// Function to find the union of two sorted arrays using set
//brute force approach
// Time Complexity: O(nlogn + mlogm) where n and m are the sizes of the two arrays
// Space Complexity: O(n + m) for storing the unique elements in a set
// vector<int> unionOfTwoSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
//     set<int> resultSet; // Using set to store unique elements

//     // Insert elements from the first array
//     for (int num : arr1) {
//         resultSet.insert(num);
//     }

//     // Insert elements from the second array
//     for (int num : arr2) {
//         resultSet.insert(num);
//     }

//     // // Convert the set back to a vector
//     // vector<int> result(resultSet.begin(), resultSet.end());
//     vector<int> result;
//     for (const auto& num : resultSet) {
//         result.push_back(num);
//     }
//     return result;
// }
//optimal approach
// Time Complexity: O(n + m) where n and m are the sizes of the two arrays
// Space Complexity: O(m+n) for the result vector
vector<int> unionOfTwoSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result; // Vector to store the union of the two arrays
    int i = 0, j = 0; // Pointers for traversing both arrays

    // Traverse both arrays until we reach the end of either one
    while (i < arr1.size() && j < arr2.size()) {
        // If the current element in arr1 is smaller or equal, add it to the result
        if (arr1[i] <= arr2[j]) {
            // To avoid duplicates, check if the last added element is different
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
        }
        // If the current element in arr2 is smaller, add it to the result
        else {
            if (result.empty() || result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
            j++;
        }
    }

    // Add any remaining elements from arr1
    while (i < arr1.size()) {
        if (result.empty() || result.back() != arr1[i]) {
            result.push_back(arr1[i]);
        }
        i++;
    }

    // Add any remaining elements from arr2
    while (j < arr2.size()) {
        if (result.empty() || result.back() != arr2[j]) {
            result.push_back(arr2[j]);
        }
        j++;
    }

    return result; // Return the union of the two sorted arrays
}

// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << endl;
}
// Main function to test the union of two sorted arrays
int main() {
    vector<int> arr1 = {1, 2, 4, 5, 6};
    vector<int> arr2 = {2, 3, 5, 7};

    vector<int> unionResult = unionOfTwoSortedArrays(arr1, arr2);

    cout << "Union of the two sorted arrays: ";
    printVector(unionResult);

    return 0;
}

