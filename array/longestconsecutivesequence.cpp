#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//brute force O(n^2) solution
// time complexity: O(n^2)
// space complexity: O(1)
bool ls(vector<int>arr,int num){
    for (int i = 0; i < arr.size(); i++)
    {
      if(arr[i]==num){
        return true;
      }
    }
    return false;
    
}
int longestConsecutiveSequenceBruteForce(vector<int>& nums) {
    if (nums.empty()) return 0;
    int longestStreak = 1;

    for (int i = 0; i < nums.size(); i++) {
        int currentNum = nums[i];
        int currentStreak = 1;

        while(ls(nums,currentNum+1)==true){
            currentNum++;
            currentStreak++;

        }
        longestStreak=max(currentStreak,longestStreak);
    }
    return longestStreak;
}
//better solution
// time complexity: O(nlogn) due to sorting
// space complexity: O(1)
int longestConsecutiveSequenceBetter(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int longestStreak = 1, currentStreak = 0,lastsmaller=INT32_MIN;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]-1 == lastsmaller){
            currentStreak++;
            lastsmaller = nums[i];
        }
      else  if (nums[i] != lastsmaller) {
            currentStreak = 1;
            lastsmaller = nums[i];
        }
            longestStreak = max(longestStreak, currentStreak);
    }
    return longestStreak;
}
// This code finds the length of the longest consecutive elements sequence in an unsorted array.
// It uses an unordered_set to achieve an average time complexity of O(n).
// The algorithm works by first inserting all elements into the set, then iterating through each element
// and checking if it is the start of a sequence (i.e., if the previous element is not in the set).
// If it is, it counts the length of the sequence by checking for consecutive elements in the set.
int longestConsecutiveSequence(vector<int>& nums) {
    // unordered_set<int> numSet(nums.begin(), nums.end());
    unordered_set<int> numSet;
    for (int num : nums) {
        numSet.insert(num);
    }
    int longestStreak = 0;

    for (int num : nums) {
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of longest consecutive sequence: " << longestConsecutiveSequenceBruteForce(nums) << endl;
    return 0;
}
