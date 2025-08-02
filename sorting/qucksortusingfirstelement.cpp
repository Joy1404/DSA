#include<iostream>
using namespace std;
// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the first element as pivot
    int i = low + 1;
    int j = high;

    while (i <= j) {
        // Find the first element greater than the pivot
        while (i <= high - 1 && arr[i] <= pivot) i++;
        // Find the first element less than the pivot
        while (j >= low + 1 && arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    // Place the pivot in its correct position
    swap(arr[low], arr[j]);
    return j;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Main function to test QuickSort
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}