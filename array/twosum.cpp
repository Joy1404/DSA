#include<bits/stdc++.h>
using namespace std;
//brute force solution for Two Sum problem
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// vector<int> twoSumBruteForce(vector<int>& nums, int target) {
//     vector<int> result; // Vector to store the result indices
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             if (nums[i] + nums[j] == target) {
//                 result.push_back(i); // Store the index of the first number
//                 result.push_back(j); // Store the index of the second number
                  //or,return {i,j}
//                 return result; // Return the result immediately
//             }
//         }
//     }
//     return result; // Return an empty vector if no pair is found
// }
//optimal solution for Two Sum problem
// Time Complexity: O(n)+ O(n) = O(n)
// The first O(n) is for iterating through the array, and the second O(n) is for checking the map.
// Space Complexity: O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // Map to store the number and its index
    vector<int> result; // Vector to store the result indices

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Calculate the complement
        if (num_map.find(complement) != num_map.end()) {
            // If complement exists in the map, we found a pair
            result.push_back(num_map[complement]);
            result.push_back(i);
            return result; // Return the result immediately
            // or,return {num_map[complement],i};
            //or return "Yes";
        }
        num_map[nums[i]] = i; // Store the index of the current number
        // return "No"; // If no pair is found, return "No"
    }
    
    return result; // Return an empty vector if no pair is found
}
//optimal approach for find yes or no for Two Sum problem using sorting and two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
bool twoSumExistsOptimized(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); // Sort the array
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return true; // Found a pair
        } else if (sum < target) {
            left++; // Move left pointer to the right
        } else {
            right--; // Move right pointer to the left
        }
    }
    return false; // No pair found
}

// Example usage
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices of the two numbers that add up to " << target << " are: "
             << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers add up to " << target << endl;
    }
    
    return 0;
}