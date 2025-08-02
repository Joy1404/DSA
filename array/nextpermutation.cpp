#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//brute force approach to find the next permutation
// This approach generates all permutations and finds the next one.
// However, it is not efficient for large sequences due to its factorial time complexity.
void nextPermutationBruteForce(vector<int>& nums) {
   //generate all permutations
    sort(nums.begin(), nums.end());
    do {
        // This loop will run until the next permutation is found
    } while (next_permutation(nums.begin(), nums.end()));
    // The next_permutation function will rearrange the numbers in the vector to the next lexicographical order
}

// optimal next permutation algorithm
// This function generates the next lexicographical permutation of a sequence of numbers.
// Function to find the next permutation of a given sequence
void nextPermutation(vector<int>& nums) {
    int n= nums.size();
    int idx=-1;
    // Step 1: Find the largest index i such that nums[i] < nums[i + 1]
    for(int i=n-2; i>=0; i--) {
        if(nums[i] < nums[i + 1]) {
            idx = i;
            break;
        }
    }
    // If no such index exists, reverse the entire array
    if (idx == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    // Step 2: Find the largest index j greater than i such that nums[i] < nums[j]
    for(int j=n-1; j>idx; j--) {
        if(nums[j] > nums[idx]) {
            // Step 3: Swap the values at indices idx and j
            swap(nums[idx], nums[j]);
            break;
        }
    }
    // Step 4: Reverse the subarray from i + 1 to the end
    reverse(nums.begin() + idx + 1, nums.end());
}
// Function to print the vector
void printVector(const vector<int>& nums) {
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
// Main function to test the nextPermutation function
int main() {
    vector<int> nums = {1, 2, 3};
    cout << "Original vector: ";
    printVector(nums);
    nextPermutation(nums);
    cout << "Next permutation: ";
    printVector(nums);
    return 0;
}