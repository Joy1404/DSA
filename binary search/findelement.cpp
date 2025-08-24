#include<bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // To avoid potential overflow
        if (arr[mid] == k) {
            return mid; // Element found
        } else if (arr[mid] < k) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    int result = findElement(arr, n, k);
    if (result != -1) {
        cout << "Element is present at index " << result << endl;
    } else {
        cout << "Element is not present in array" << endl;
    }
    return 0;
}