#include<bits/stdc++.h>
using namespace std;
void explaindeque(){
    deque<int>dq;
    dq.push_back(1);
    dq.emplace_back(2);

    dq.push_front(3);
    dq.emplace_front(4);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();

    //rest functions similar to vector
    //begin(),end(),rbegin(),rend()
    //insert,erase,pop_back,clear,swap
}