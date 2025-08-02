#include<bits/stdc++.h>
using namespace std;
// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in the correct position
    return i + 1; // Return the partition index
}

// Function to perform quicksort
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Partitioning index
        quicksort(arr, low, pivotIndex - 1); // Recursively sort the left subarray
        quicksort(arr, pivotIndex + 1, high); // Recursively sort the right subarray
    }
}
// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Main function to test the quicksort implementation
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    
    cout << "Original array: ";
    printArray(arr);
    
    quicksort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}