#include<bits/stdc++.h>
using namespace std;
// problem statement : You are given a list of stones with positive integer weights.
// Each turn, you choose the two heaviest stones and smash them together.
// If the stones have equal weight, both stones are destroyed.
// If they have different weights, the lighter stone is destroyed, and the heavier stone's weight is reduced by the lighter stone's weight.
// The process continues until there is at most one stone left.
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(), stones.end());

    while (pq.size() > 1) {
        int stone1 = pq.top(); pq.pop();
        int stone2 = pq.top(); pq.pop();

        if (stone1 != stone2) {
            pq.push(stone1 - stone2);
        }
    }

    return pq.empty() ? 0 : pq.top();
}
int main() {
    vector<int> stones = {2,7,4,1,8,1};
    cout << "Last stone weight: " << lastStoneWeight(stones) << endl;
    return 0;
}