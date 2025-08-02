#include<bits/stdc++.h>
using namespace std;
//brute force solution to find the second largest and second smallest elements in an array
//time complexity: O(nlogn+n) due to sorting and then iterating through the array
//space complexity: O(1) as we are not using any extra space except for the input array
// int secondLargestElementBruteForce(int arr[], int n) {
//     sort(arr, arr + n); // Sort the array
//    int largest=arr[n - 1]; // The last element after sorting is the largest
//     for (int i = n - 2; i >= 0; i--) {
//         if (arr[i] != largest) { // Find the second largest
//             return arr[i];
//         }
//     }
//     return INT_MIN; // If no second largest found
// }
//better approach
// Function to find the second largest element in an array
// Time complexity: O(n) for finding the largest
// and O(n) for finding the second largest, resulting in O(2n) overall
// Space complexity: O(1) as we are not using any extra space except for the input array

int secondLargestbetter(int arr[],int n){
     int largest = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    int slargest=INT_MIN;
     for (int i = 0; i < n; i++) {
        if (arr[i] > slargest && arr[i]!=largest) {
            slargest = arr[i];
        }
    }
    return slargest;
}
//optimal 
// Function to find the second largest element in an array
int secondLargestElement(int arr[], int n) {
    int largest = INT_MIN, slargest = INT_MIN; // Initialize first and second largest
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            slargest = largest; // Update second largest
            largest = arr[i]; // Update first largest
        } else if (arr[i] > slargest && arr[i] != largest) {
            slargest = arr[i]; // Update second largest if current is not equal to first
        }
    }
    return slargest; // Return the second largest element found
}
// Function to find the second smallest element in an array
int secondSmallestElement(int arr[], int n) {
    int smallest = INT_MAX, ssmallest = INT_MAX; // Initialize first and second smallest
    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            ssmallest = smallest; // Update second smallest
            smallest = arr[i]; // Update first smallest
        } else if (arr[i] < ssmallest && arr[i] != smallest) {
            ssmallest = arr[i]; // Update second smallest if current is not equal to first
        }
    }
    return ssmallest; // Return the second smallest element found
}
// Main function to test the second largest and second smallest functions
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int secondLargest = secondLargestElement(arr, n);
    int secondSmallest = secondSmallestElement(arr, n);
    
    cout << "The second largest element is: " << secondLargest << endl;
    cout << "The second smallest element is: " << secondSmallest << endl;
    
    return 0;
}