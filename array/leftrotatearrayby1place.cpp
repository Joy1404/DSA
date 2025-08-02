#include<bits/stdc++.h>
using namespace std;
// Function to left rotate an array by one place
void leftRotateByOne(int arr[], int n) {
    if (n <= 1) return; // No need to rotate if array has 0 or 1 element

    int first = arr[0]; // Store the first element
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i]; // Shift elements to the left
    }
    arr[n - 1] = first; // Place the first element at the end
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Main function to test the leftRotateByOne function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    leftRotateByOne(arr, n);

    cout << "Array after left rotation by one place: ";
    printArray(arr, n);

    return 0;
}