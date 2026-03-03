#include<bits/stdc++.h>
using namespace std;
class Queue{
    int front,rear,capacity,current_size;
    int *arr;
    public:
    Queue(int c){
        capacity=c;
        front=-1;
        rear=-1;
        current_size=0;
        arr=new int[capacity];
    }
    void push(int x){
       if(current_size==capacity){
            cout<<"Queue overflow"<<endl;
            return;
        }
        if(current_size==0){
            front=0;
            rear=0;
        }
        else{
            rear=(rear+1)%capacity;
        }
        arr[rear]=x;
        current_size++;
    }
     
    int pop(){
        if(current_size==0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        int x=arr[front];
        if(current_size==1){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%capacity;
        }
        current_size--;
        return x;
    }
    int size(){
        return current_size;
    }
    bool isEmpty(){
        return current_size==0;
    }
};
int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.size()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}