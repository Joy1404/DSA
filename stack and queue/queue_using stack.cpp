#include<bits/stdc++.h>
using namespace std;
// time complexity of push is O(n) and rest is O(1)
// push -> first we pop all elements from s1 and push them to s2, then we push the new element to s1 and then we pop all elements from s2 and push them back to s1
class Queue{
    public:
    stack<int>s1,s2;
    void push(int data){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int peek(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return s1.top();
    }
    int pop(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x=s1.top();
        s1.pop();
        return x;
    }
    bool isEmpty(){
        return s1.empty();
    }
};
// method 2
// time complexity of push is O(1) and rest is O(n)
// for push -> we simply push the new element to s1
// for pop and peek -> if s2 is not empty then we simply return the top element of s2, if s2 is empty then we pop all elements from s1 and push them to s2 and then we return the top element of s2
class Queue{
    public:
    stack<int>s1,s2;
    void push(int data){
        s1.push(data);
    }
    int peek(){
       if(!s2.empty()){
            return s2.top();
        }
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    int pop(){
       if(!s2.empty()){
            int x=s2.top();
            s2.pop();
            return x;
        }
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int x=s2.top();
        s2.pop();
        return x;
    }
    bool isEmpty(){
        return s1.empty();
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"Front element: "<<q.peek()<<endl;
    cout<<"Popped element: "<<q.pop()<<endl;
    cout<<"Front element after pop: "<<q.peek()<<endl;
    return 0;
}