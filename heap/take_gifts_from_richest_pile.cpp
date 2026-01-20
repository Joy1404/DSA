#include<bits/stdc++.h>
using namespace std;

// problem statement : You have a collection of gift piles, each pile has a certain number of gifts represented by a positive integer. You can perform the following operation k times: select the pile with the maximum number of gifts, take the square root (floor value) of that number of gifts, and replace the pile's gift count with this new value. After performing k operations, return the state of all gift piles.
vector<int> takeGiftsFromRichestPile(vector<int>& gifts, int k) {
    priority_queue<int> pq(gifts.begin(), gifts.end());

    while (k-- && !pq.empty()) {
        int richest = pq.top();
        pq.pop();
        int taken = sqrt(richest);
        pq.push(taken);
    }

    vector<int> remainingGifts;
    while (!pq.empty()) {
        remainingGifts.push_back(pq.top());
        pq.pop();
    }

    return remainingGifts;
} 