#include<bits/stdc++.h>
using namespace std;
// brute force
// using four nested loops
// O(n^4) time complexity
vector<vector<int>> foursum_brute_force(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    set<vector<int>> unique_res; // to avoid duplicates
    if (n < 4) return res;

    for (int i = 0; i < n ; ++i) {
        for (int j = i + 1; j < n ; ++j) {
            for (int k = j + 1; k < n ; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        // insert in sorted order to avoid duplicates
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                        sort(quad.begin(), quad.end());
                        unique_res.insert(quad);
                    }
                }
            }
        }
    }
    res.assign(unique_res.begin(), unique_res.end());
    return res;
}

// better solution
// using  hashset
vector<vector<int>> foursum_hashset(vector<int>&nums ,int target){
    int n =nums.size();
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long>hashset;
            for(int k=j+1;k<n;k++){
                long long sum = nums[i]+nums[j];
                sum+=nums[k];
                long long fourth = target - sum;
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> quad = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(quad.begin(), quad.end());
                    st.insert(quad);
                } 
                 hashset.insert(nums[k]);
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

// optimal approach
// O(n^3) time complexity
// using sorting and two pointers
vector<vector<int>> foursum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 4) return res;

    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n ; ++i) {
        for (int j = i + 1; j < n ; ++j) {
            int left = j + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    ++left; --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1]) ++j; // skip duplicates
        }
        while (i + 1 < n && nums[i] == nums[i + 1]) ++i; // skip duplicates
    }
    
    return res;
}
int main(){
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = foursum(nums, target);
    for (const auto& quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}