#include<bits/stdc++.h>
using namespace std;
void explainpq(){
    priority_queue<int>pq;
    pq.push(5);//5
    pq.push(2);//5,2
    pq.push(8);//8,5,2
    pq.push(10);//10,8,5,2
    pq.emplace(10);
    cout<<pq.top()<<endl; // 10
    pq.pop(); // 8,5,2
    cout<<pq.top()<<endl; // 8
    //size,swap,empty same as others

    //min heap
    priority_queue<int,vector<int>,greater<int>>pq2;
    pq2.push(5);//5 
    pq2.push(2);//2,5
    pq2.push(8);//2,5,8
    pq2.push(10);//2,5,8,10
    cout<<pq2.top()<<endl; // 2
    //push o(log(n))
    //pop o(log(n))
    //top o(1)
}