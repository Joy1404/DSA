#include<bits/stdc++.h>
using namespace std;
void explainlist(){
    list<int>ls;
    ls.push_back(1);
    ls.emplace_back(2);

    ls.push_front(3);
    ls.emplace_front(2,4);

    //rest functions similar to vector
    //begin(),end(),rbegin(),rend()
    //insert,erase,pop_back,clear,swap
}