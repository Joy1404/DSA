#include<bits/stdc++.h>
using namespace std;
// Function to find the single number in an array where every other number appears twice using nested loops
// Note: This approach is not efficient for large arrays, as it has O(n^2) time complexity. space complexity is O(1).
// int singleNumberNestedLoops(vector<int>& nums) {
//     // for (int i = 0; i < nums.size(); i++) {
//     //     bool found = false;
//     //     for (int j = 0; j < nums.size(); j++) {
//     //         if (i != j && nums[i] == nums[j]) {
//     //             found = true;
//     //             break;
//     //         }
//     //     }
//     //     if (!found) {
//     //         return nums[i];
//     //     }
//     // }
//     // return -1; // This line should never be reached if input is valid
//     for(int i = 0; i < nums.size(); i++) {
//         int count = 0;
//         for(int j = 0; j < nums.size(); j++) {
//             if(nums[i] == nums[j]) {
//                 count++;
//             }
//         }
//         if(count == 1) {
//             return nums[i];
//         }
//     }
// }
// Function to find the single number in an array where every other number appears twice using hash array
// Note: This approach assumes that the numbers are non-negative and within a certain range.
//// It has O(3n) time complexity and O(m) space complexity, where m is the maximum number in the array.
// int singleNumberHashArray(vector<int>& nums) {
//     int maxi=nums[0];
//    for(int i=0;i<nums.size();i++){
//     maxi=max(maxi,nums[i]);
//    }
//     vector<int> hash(maxi+1, 0);
//     for(int num : nums) {
//         hash[num]++;
//     }
//     for(int i = 0; i < hash.size(); i++) {
//         // if(hash[i] == 1) {
//         //     return i;
//         // }
//         if(hash[nums[i]] == 1) {
//             return nums[i];
//         }
//     }
//     return -1; // This line should never be reached if input is valid
// }

// Function to find the single number in an array where every other number appears twice using map
// Note: This approach uses a hash map to count occurrences of each number.
//// It has O(n)+O(m) time complexity and O(m) space complexity, where m is the number of unique elements in the array.
// int singleNumberMap(vector<int>& nums) {
//     unordered_map<int, int> countMap;
//     for(int num : nums) {
//         countMap[num]++;
//     }
//     for(auto& entry : countMap) {
//         if(entry.second == 1) {
//             return entry.first;
//         }
//     }
//     return -1; // This line should never be reached if input is valid
// }
// Function to find the single number in an array where every other number appears twice using XOR
// Note: This approach has O(n) time complexity and O(1) space complexity.
int singleNumberXOR(vector<int>& nums) {
    int result = 0;
    for(int num : nums) {
        result ^= num;
    }
    return result;
}
// Main function to test the single number functions
int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    
    // Uncomment the function you want to test
    // cout << "Single number using nested loops: " << singleNumberNestedLoops(nums) << endl;
    // cout << "Single number using hash array: " << singleNumberHashArray(nums) << endl;
    // cout << "Single number using map: " << singleNumberMap(nums) << endl;
    cout << "Single number using XOR: " << singleNumberXOR(nums) << endl;

    return 0;
}