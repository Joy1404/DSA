#include<bits/stdc++.h>
using namespace std;

class MinStack1 {
    stack<pair<int,int>> st;
    public:
    void push(int x) {
        if(st.empty()){
            st.push({x,x});
        }
        else{
            int minVal=st.top().second;
            st.push({x,min(x,minVal)});
        }
    }
    int getMin() {
        return st.top().second;
    }
    int top() {
        return st.top().first;
    }
    void pop() {
        st.pop();
    }
};
class MinStack2 {
    stack<int> st;
    int minVal;
    public:
    void push(int x) {
        if(st.empty()){
            st.push(x);
            minVal=x;
        }
        else{
            if(x<minVal){
                st.push(2*x-minVal); // Store the previous minimum value in the stack
                minVal=x;
            }
            else{
                st.push(x);
            }
        }
    }
    int getMin() {
        return minVal;
    }
    int top() {
        if(st.top()<minVal){
            return minVal;
        }
        else{
            return st.top();
        }
    }
    void pop() {
        if(st.top()<minVal){
            minVal=2*minVal-st.top();
        }
        st.pop();
    }
};
int main(){
    MinStack1 minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum element: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl; // Returns 0
    cout << "Minimum element: " << minStack.getMin() << endl; // Returns -2
    return 0;
}