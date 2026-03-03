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
class Stack{
    public:
    Node* top;
    int size;
    Stack(){
        top=NULL;
        size=0;
    }
    void push(int data){
        Node* newNode=new Node(data);
        newNode->next=top;
        top=newNode;
        size++;
    }
    void pop(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
        size--;
    }
    int peek(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return top==NULL;
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Top element: "<<s.peek()<<endl;
    cout<<"Stack size: "<<s.getSize()<<endl;
    s.pop();
    cout<<"Top element after pop: "<<s.peek()<<endl;
    cout<<"Stack size after pop: "<<s.getSize()<<endl;
    return 0;
}