#include<bits/stdc++.h>
using namespace std;

// koko cant to next pile until she finishes the current pile
// she can decide her eating speed k (bananas per hour)
// she has h hours to finish all the piles
// return the minimum integer k such that she can eat all the bananas within h hours
// if she eats k bananas from a pile of size p, and p < k, she will finish the pile in 1 hour
// if she eats k bananas from a pile of size p, and p >= k, she will finish the pile in ceil(p/k) hours

// bruteforce approach
// time complexity: O(n * m) where n is the number of piles and m is the maximum pile size
// space complexity: O(1)
int minEatingSpeed(vector<int>& piles, int h) {
    int mx = *max_element(piles.begin(), piles.end());
    for (int k = 1; k <= mx; k++) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // to avoid floating point operations
        }
        if (hours <= h) {
            return k;
        }
    }
    return mx;
}

// optimal approach
// time complexity: O(n log m) where n is the number of piles and m is the maximum pile size
// space complexity: O(1)
 bool validmid(vector<int>& piles, int mid, int h) {
        long long hours = 0;
        for (int pile : piles) {
            // hours += ceil((double)pile / mid);
            // hours += (pile + mid - 1) / mid; // to avoid floating point operations
            hours += (pile + mid - 1) / mid;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int low = 1, high = mx, ans = mx;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (validmid(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans; //return low;
    }
int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << minEatingSpeed(piles, h) << endl;
    return 0;
}