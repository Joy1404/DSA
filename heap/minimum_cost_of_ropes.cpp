#include<bits/stdc++.h>
using namespace std;
// problem statement : Given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to the sum of their lengths. We need to connect the ropes with minimum cost.
int minCost(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        // for(int num : arr){
        //     pq.push(num);
        // }
        int cost = 0;
        while(pq.size()>1){
            int f = pq.top();
            pq.pop();
           f+=pq.top();
            pq.pop();
            cost+=f;
            pq.push(f);
        }
        return cost;
    }

    int main(){
        vector<int> ropes = {4, 3, 2, 6};
        cout << "Minimum cost to connect ropes: " << minCost(ropes) << endl;
        return 0;
    }