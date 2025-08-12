#include <bits/stdc++.h>
using namespace std;
// brute force
// it is based on the idea of checking all triplets
// we can use a set to store unique triplets
// we can sort the triplet before inserting it into the set
// time complexity is O(n^3)
// space complexity is O(n)
vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> uniqueTriplets;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
            }
        }
    }
    vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
    return result;
}

// better approach
//  it is based on the idea of using a hash set to find the third element
//  time complexity is O(n^2)
//  space complexity is O(n)
vector<vector<int>> threeSumBetter(vector<int> &nums)
{
    set<vector<int>> uniqueTriplets;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
    return result;
}
//optimal approach
//  it is based on the idea of sorting the array and using two pointers
//  time complexity is O(n^2)
//  space complexity is O(1)
vector<vector<int>> threeSumOptimal(vector<int> &nums)
{
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    for (const auto &triplet : result)
    {
        cout << "[";
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}