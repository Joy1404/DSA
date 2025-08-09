#include<iostream>
#include<unordered_map>
using namespace std;

//brute force
//time complexity: O(n^3)
//space complexity: O(1)
// it is based on generating all subarrays
int subarraySumBruteForce(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currSum = 0;
            for(int l=i; l<=j; l++) {
                currSum += arr[l];
            }
                if (currSum == k) {
                    count++;
                }
        }
    }
    return count;
}

// better solution
// time complexity: O(n^2)
// space complexity: O(1)
int subarraySumBetter(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int currSum = 0;
        for (int j = i; j < n; j++) {
            currSum += arr[j];
            if (currSum == k) {
                count++;
            }
        }
    }
    return count;
}
//optimal solution
//time complexity: O(n)
//space complexity: O(n)
int subarraySum(int arr[], int n, int k) {
    // Create a map to store the frequency of prefix sums
    unordered_map<int, int> prevSum;
    prevSum[0] = 1; // Initialize with sum 0 to handle cases where subarray starts from index 0
    int count = 0;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        // Check if there is a subarray (ending at index i) with sum equal to k
        int remove = currSum - k;
        count += prevSum[remove];
        prevSum[currSum]++;
    }

    return count;
}

int main() {
    int arr[] = {1, 2, 3,-3,1,1,1, 4, 2,-3};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of subarrays with sum " << k << ": " << subarraySumBruteForce(arr, n, k) << endl;
    return 0;
}