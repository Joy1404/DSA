#include<iostream>
#include<vector>
#include<map>
#include<climits>

using namespace std;
//brute force
// time complexity: O(n^2)
// space complexity: O(1)
vector<int> majorityelement(vector<int>& nums){
    vector<int>ans;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(ans.size()==0 || ans[0] != nums[i]){
            int count = 0;
            for(int j=0;j<n;j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count > n/3){
                ans.push_back(nums[i]);
            }
        }
    }
    return ans;
}
//better
//time complexity: O(n)
//space complexity: O(n)
// it is based on the HashMap
vector<int> majorityelementbetter(vector<int>& nums){
    vector<int>ans;
    map<int,int>mp;
    int mm = nums.size()/3+1;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
        if(mp[nums[i]]==mm){
            ans.push_back(nums[i]);
        }
        if(ans.size() == 2) {
            break; // We can only have at most two majority elements
        }
    }
    return ans;
}
// optimal
// time complexity: O(n)
// space complexity: O(1)
// it is based on the Boyer-Moore Voting Algorithm
vector<int> majorityelementoptimal(vector<int>& nums) {
    vector<int> ans;
    int count1 = 0, count2 = 0, el1 = INT_MIN, el2 = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
       if (count1 == 0 && nums[i] != el2) {
        el1 = nums[i];
        count1 = 1;
    } else if (count2 == 0 && nums[i] != el1) {
        el2 = nums[i];
        count2 = 1;
        if (nums[i] == el1) {
            count1++;
        } else if (nums[i] == el2) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }
}
count1 = count2 = 0;
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == el1) count1++;
    if (nums[i] == el2) count2++;
}
if (count1 >= nums.size() / 3+1) ans.push_back(el1);
if (count2 >= nums.size() / 3+1) ans.push_back(el2);
return ans;
}
int main() {
    vector<int>nums = {3, 2, 3, 2, 2};
    vector<int>ans = majorityelementoptimal(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
