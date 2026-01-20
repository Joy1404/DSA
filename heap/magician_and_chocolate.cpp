#include<bits/stdc++.h>
using namespace std;
// problem statement : A magician has k units of time to collect chocolates from a bag. The bag contains n packets of chocolates, each packet has some number of chocolates. In one unit of time, the magician can choose a packet with maximum chocolates, collect all the chocolates from it, and then the number of chocolates in that packet reduces to half (floor value). The task is to find the maximum number of chocolates the magician can collect in k units of time.
int maxchocolates(int k, vector<int>& arr) {
    priority_queue<int> pq(arr.begin(), arr.end());
    int total_chocolates = 0;

    while(k-- && !pq.empty()) {
        int max_choco = pq.top();
        pq.pop();
        total_chocolates += max_choco;
        int half_choco = max_choco / 2;
        if (half_choco > 0) {
            pq.push(half_choco);
        }
    }

    return total_chocolates;
}