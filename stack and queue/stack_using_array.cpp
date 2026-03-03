#include<bits/stdc++.h>
using namespace std;
class Stack{
    int top;
    int capacity;
    int *arr;
    public:
    Stack(int c){
        capacity=c;
        top=-1;
        arr=new int[capacity];
    }
    void push(int x){
        if(top==capacity-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++top]=x;
    }
    int pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return top==-1;
    }
};
int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}