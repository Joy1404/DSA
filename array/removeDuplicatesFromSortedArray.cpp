#include<bits/stdc++.h>
using namespace std;
//brute force solution to remove duplicates from a sorted array using a set
// int removeDuplicatesBruteForce(vector<int>& nums) {
//     set<int> uniqueElements;
//     for (int num : nums) {
//         uniqueElements.insert(num);
//     }
    
//     // nums.assign(uniqueElements.begin(), uniqueElements.end());
//     int idx = 0;
//     for(auto it:uniqueElements){
//        nums[idx++] = it;
//     }
//     // return nums.size();
//     return idx; // Return the count of unique elements
// }
// // Example usage
// int main() {
//     vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
//     int newSize = removeDuplicatesBruteForce(nums);
    
//     cout << "Number of unique elements: " << newSize << endl;
//     cout << "Array after removing duplicates: ";
//     for (int i = 0; i < newSize; i++) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
    
//     return 0;
// }

//optimal solution to remove duplicates from a sorted array
//time complexity: O(n) where n is the number of elements in the array
//space complexity: O(1) as we are not using any extra space except for the input array
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int uniqueIndex = 0; // Index to place the next unique element
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[uniqueIndex]) {
            uniqueIndex++;
            nums[uniqueIndex] = nums[i];
        }
    }
 
    return uniqueIndex + 1; // Return the count of unique elements
}
// Example usage
int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newSize = removeDuplicates(nums);
    
    cout << "Number of unique elements: " << newSize << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}