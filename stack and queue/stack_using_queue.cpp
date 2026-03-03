#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    queue<int> q;
    void push(int data){
        q.push(data);
        int size=q.size();
        for(int i=1;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int peek(){
        if(q.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return q.front();
    }
    int pop(){
        if(q.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int x=q.front();
        q.pop();
        return x;
    }
    bool isEmpty(){
        return q.empty();
    }
    int size(){
        return q.size();
    }
};
// method 2 using two queues
class Stack2{
    public:
    queue<int> q1;
    queue<int> q2;
    void push(int data){
        q1.push(data);
    }
    int peek(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        q2.push(x);
        q1.pop();
        swap(q1,q2);
        return x;
    }
    int pop(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        q1.pop();
        swap(q1,q2);
        return x;
    }
    bool isEmpty(){
        return q1.empty();
    }
    int size(){
        return q1.size();
    }
};

int main(){
    Stack2 s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Top element: "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element after pop: "<<s.peek()<<endl;
    return 0;
}