#include <bits/stdc++.h>
using namespace std;
// m bouquets need to be made using flowers in the garden
// flowers are planted in a row and ith flower will bloom in days[i] days
// to make a bouquet, we need k adjacent flowers
// return the minimum number of days required to make m bouquets
// if it is not possible to make m bouquets, return -1
// bruteforce approach
// time complexity: O(n * d) where n is the number of flowers and d is the maximum days to bloom - min days
// space complexity: O(1)
bool canmakebouquets(vector<int> &bloomDay, int day, int m, int k)
{
    int bouquets = 0;
    int flowers = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
        {
            flowers++;
        }
        else
        {
            bouquets += flowers / k;
            flowers = 0;
        }
    }
    bouquets += flowers / k;
    if (bouquets >= m)
        return true;
    return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if (m * k > n)
        return -1;
    int maxDays = *max_element(bloomDay.begin(), bloomDay.end());
    int minDays = *min_element(bloomDay.begin(), bloomDay.end());
    for (int day = minDays; day <= maxDays; day++)
    {
        if (canmakebouquets(bloomDay, day, m, k))
            return day;
    }
    return -1;
}

// optimal approach
// time complexity: O(n log d) where n is the number of flowers and d is the maximum days to bloom - min days
// space complexity: O(1)
bool validmid(vector<int> &bloomDay, int day, int m, int k) {
    int bouquets = 0;
    int flowers = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= day) {
            flowers++;
            if (flowers == k) {   // we can form a bouquet
                bouquets++;
                flowers = 0;      // reset for next bouquet
            }
        } else {
            flowers = 0;  // reset if flower not bloomed
        }
        if (bouquets >= m) return true;
    }
    return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if (m * k > n)
        return -1;
    int maxDays = *max_element(bloomDay.begin(), bloomDay.end());
    int minDays = *min_element(bloomDay.begin(), bloomDay.end());
    int low = minDays, high = maxDays, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (validmid(bloomDay, mid, m, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans; //return low;
}
int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << minDays(bloomDay, m, k) << endl;
    return 0;
}