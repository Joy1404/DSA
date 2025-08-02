#include<bits/stdc++.h>
using namespace std;
//optimal approach to left rotate an array by d places
// Time complexity: O(2n), Space complexity: O(1)
void leftRotateByDPlaces(int arr[], int n, int d) {
    if (n <= 1 || d <= 0) return; // No need to rotate if array has 0 or 1 element or d is non-positive

    // Handle cases where d is greater than n
    d = d % n;
    if (d == 0) return;

    // Reverse the first d elements
    reverse(arr, arr + d);
    // Reverse the remaining n - d elements
    reverse(arr + d, arr + n);
    // Reverse the entire array
    reverse(arr, arr + n);
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Function to left rotate an array by one place
//time complexity: O(n+d), space complexity: O(d)
//brute force approach
// void leftRotateByDPlaces(int arr[], int n, int d) {
//     // Handle cases where d is greater than n
//     d = d % n;
//     if (d == 0) return;

//     // Create a temporary array to hold the rotated elements
//     int temp[d];
    
//     // Store the first d elements in the temporary array
//     for (int i = 0; i < d; i++) {
//         temp[i] = arr[i];
//     }

//     // Shift the remaining elements to the left
//     for (int i = d; i < n; i++) {
//         arr[i - d] = arr[i];
//     }

//     // Copy the elements from the temporary array back to the end of the original array
//     // for (int i = 0; i < d; i++) {
//     //     arr[n - d + i] = temp[i];
//     // }
//     for (int i = n - d; i < n; i++) {
//         arr[i] = temp[i - (n - d)];
//     }
// }
// // Function to print the array
// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// Main function to test the leftRotateByDPlaces function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    cout << "Original array: ";
    printArray(arr, n);

    leftRotateByDPlaces(arr, n, d);

    cout << "Array after left rotation by " << d << " places: ";
    printArray(arr, n);

    return 0;
}