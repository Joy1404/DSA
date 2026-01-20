#include<bits/stdc++.h>
using namespace std;
// problem statement : You have a list of projects, each project has a certain profit represented by a positive integer. You can undertake k projects. Each time you undertake a project, you earn its profit, but the profit of that project decreases by 1 for future considerations (if it becomes zero or negative, it cannot be undertaken again). The task is to maximize the total profit after undertaking k projects.
int maximizeProfit(int k, vector<int>& profits) {
    priority_queue<int> pq(profits.begin(), profits.end());
    int total_profit = 0;

    while(k-- && !pq.empty()) {
        int max_profit = pq.top();
        pq.pop();
        total_profit += max_profit;
        int reduced_profit = max_profit-1;
        if (reduced_profit > 0) {
            pq.push(reduced_profit);
        }
    }

    return total_profit;
}
int main() {
    vector<int> profits = {6,4,2,3};
    int k = 5;
    cout << "Maximum Profit: " << maximizeProfit(k, profits) << endl;
    return 0;
}