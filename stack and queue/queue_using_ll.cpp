#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Queue{
    public:
    Node* front;
    Node* rear;
    int size;
    Queue(){
        front=NULL;
        rear=NULL;
        size=0;
    }
    void push(int data){
        Node* newNode=new Node(data);
        if(front==NULL){
            front=rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
        size++;
    }
    void pop(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            rear = NULL; // Reset rear to NULL when queue becomes empty
            return;
        }
        Node* temp=front;
        front=front->next;
        delete temp;
        size--;
    }
    int peek(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            rear = NULL; // Reset rear to NULL when queue becomes empty
            return -1;
        }
        return front->data;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return front==NULL;
    }
};