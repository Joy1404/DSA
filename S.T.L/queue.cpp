#include<bits/stdc++.h>
using namespace std;
void explainqueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);
    cout << "Front element: " << q.front() << endl; // Output: 1
    cout << "Back element: " << q.back() << endl;   // Output: 3
    q.back()+=5;
    cout << "Back element after modification: " << q.back() << endl; // Output: 8
    cout << "Size of queue: " << q.size() << endl; // Output: 3
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 2
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: No
    //first in first out
    // size,swap,empty like stack

}