#include<bits/stdc++.h>
using namespace std;
void explainstack(){
    stack<int>s;
    s.push(1);//1
    s.push(2);//2,1
    s.push(3);//3,2,1
    s.push(4);//4,3,2,1
    s.emplace(5);//5,4,3,2,1

    s.pop();//4,3,2,1
    s.top();//5    "**s[2] is not valid"
    s.size();//4
    s.empty();//false
    stack<int>s2;
    s.swap(s2);//s2=4,3,2,1
    //time complexity  is O(1)
    //last in first out
    //rest functions similar to vector
    //begin(),end(),rbegin(),rend()
    //insert,erase,pop_back,clear,swap
}