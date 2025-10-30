#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
//brute force approach using hashing
//time complexity: O(n)
//space complexity: O(n)
bool detectLoop_hashing(Node* head){
    // unordered_set<Node*> s;
    map<Node*,int>s;
    Node* temp=head;
    while(temp!=NULL){
        //if we have already seen this node, then there is a loop
        if(s.find(temp)!=s.end()){
            return true;
        }
        s[temp]=1;
        temp=temp->next;
    }
    return false;
}
//optimal approach using floyd's cycle detection algorithm
//time complexity: O(n)
//space complexity: O(1)
// approach: we use two pointers, slow and fast. slow moves one step at a time, while fast moves two steps at a time. if there is a loop, they will eventually meet.
// if there is no loop, fast will reach the end of the list.
bool detectLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    //creating a loop for testing
    head->next->next->next->next->next=head->next;
    if(detectLoop(head)){
        cout<<"Loop detected using optimal approach"<<endl;
    }
    else{
        cout<<"No Loop detected using optimal approach"<<endl;
    }
    if(detectLoop_hashing(head)){
        cout<<"Loop detected using hashing approach"<<endl;
    }
    else{
        cout<<"No Loop detected using hashing approach"<<endl;
    }
    return 0;
}