#include<bits/stdc++.h>
using namespace std;
// Function to sort an array using the 0's, 1's, and 2's without dutch national flag algorithm
// This function sorts an array containing only 0's, 1's, and 2's in linear time and constant space.
// The function counts the occurrences of each number and then fills the array with sorted values.
// Time Complexity: O(2n), where n is the number of elements in the array.
// Space Complexity: O(1), since we are using a fixed amount of extra space for counting.
// void sort012(int arr[], int n) {
    // int count[3] = {0}; // Count of 0's, 1's, and 2's

    // // Count occurrences of 0's, 1's, and 2's
    // for (int i = 0; i < n; i++) {
    //     count[arr[i]]++;
    // }

    // // Fill the array with sorted values
    // int index = 0;
    // for (int i = 0; i < 3; i++) {
    //     while (count[i] > 0) {
    //         arr[index++] = i;
    //         count[i]--;
    //     }
    // }
    // // Alternative approach without using the count array
    // int cnt0=0, cnt1=0, cnt2=0;
    // // Count occurrences of 0's, 1's, and 2's
    // for (int i = 0; i < n; i++) {
    //     if (arr[i] == 0) cnt0++;
    //     else if (arr[i] == 1) cnt1++;
    //     else if (arr[i] == 2) cnt2++;
    // }
    // // Fill the array with sorted values
    // int index = 0;
    // for (int i = 0; i < cnt0; i++) {
    //     arr[index++] = 0;
    // }
    // for (int i = 0; i < cnt1; i++) {
    //     arr[index++] = 1;
    // }
    // for (int i = 0; i < cnt2; i++) {
    //     arr[index++] = 2;
    // }
// }
void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Main function to test the sorting function
int main() {
    int arr[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    sort012(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}