#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pq; // max heap by default
    pq.push(10);
    pq.push(20);
    pq.push(11);
    pq.push(18);
    pq.push(15);
    cout<< pq.top() << endl; // 20
    // remove the top element
    pq.pop();
    cout<< pq.top() << endl; // 18
    // size of priority queue
    cout<< pq.size() << endl; // 4

    while(!pq.empty()){
        cout<< pq.top() << " ";
        pq.pop();
    }

    // min heap
    priority_queue<int,vector<int>,greater<int>>minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(11);
    minHeap.push(18);
    minHeap.push(15);
    // cout<< minHeap.top() << endl; // 10
    // // remove the top element
    // minHeap.pop();
    // cout<< minHeap.top() << endl; // 11

    while(!minHeap.empty()){
        cout<< minHeap.top() << " ";
        minHeap.pop();
    }
}