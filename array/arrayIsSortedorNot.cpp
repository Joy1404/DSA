#include<bits/stdc++.h>
using namespace std;
// bool arrayIsSortedOrNot(int arr[], int n) {
//     // Check if the array is sorted in non-decreasing order
//     for (int i = 1; i < n; i++) {
//         if (arr[i] < arr[i - 1]) {
//             return false; // If any element is less than the previous one, it's not sorted
//         }
//     }
//     return true; // If we reach here, the array is sorted
// }
bool arrayIsSortedOrNot(int arr[], int n) {
    // Check if the array is sorted in non-decreasing order
    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) {
            continue; // If the current element is greater than or equal to the previous one, continue
        } else {
            return false; // If any element is less than the previous one, it's not sorted
        }
    }
    return true; // If we reach here, the array is sorted
}
// Example usage
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (arrayIsSortedOrNot(arr, n)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }
    
    return 0;
}