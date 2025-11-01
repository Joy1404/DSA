#include<bits/stdc++.h>
using namespace std;
class node{
public:
  int data;
  node* next;
  node(int data1,node* next1){
    data=data1;
    next=next1;
  }
  node(int data1){
    data=data1;
    next=NULL;
  }
};
// brute force approach
// time complexity = O(n+n/2)=O(n)
// space complexity = O(1)
//approach: calculate length of ll and then traverse till mid-1 node and delete mid node
// return head of modified ll
node* deletemiddlenode (node* head){
node* temp = head;
int count =0;
if(head==NULL || head->next==NULL){
    return NULL;
}
while(temp!=NULL){
    count++;
    temp=temp->next;

}
int mid = count/2;
temp=head;
while(temp!=NULL){
    mid--;
    if(mid==0){
      node* mid=temp->next;
        temp->next=temp->next->next;
        free(mid);
        break;
    }
    temp=temp->next;
}
return head;
}
//optimized approach
// time complexity = O(n)
// space complexity = O(1)
// approach: use slow and fast pointer to reach mid node and delete it
node* deletemiddlenode2 (node* head){
if(head==NULL || head->next==NULL){
    return NULL;
}
node* slow=head;
node* fast=head;
node* prev=NULL;
while(fast!=NULL && fast->next!=NULL){
    prev=slow;
    slow=slow->next;
    fast=fast->next->next;
}
prev->next=slow->next;  
free(slow);
return head;
}
// more optimal 
// time complexity = O(n/2)
// space complexity = O(1)
// approach: use slow and fast pointer to reach mid node and delete it
// here we move fast pointer two steps ahead before entering the loop
// so that when fast pointer reaches end, slow pointer is at mid-1 node
// thus we can directly delete mid node without using prev pointer
node* deletemiddlenodeoptimal (node* head){
if(head==NULL || head->next==NULL){
    return NULL;
}
node* slow=head;
node* fast=head;
fast=fast->next->next;
while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
}
node * todelete=slow->next;
slow->next=slow->next->next;  
free(todelete);
return head;
}

   void printll(node* head){
    node* temp = head;
    while (temp != NULL) {  
        cout << temp->data << " ";  // print ll element
        temp = temp->next;
    }
    cout<<"\n";
   }
   int main(){
    node* head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(5);
    head->next->next->next->next->next=new node(6);
    printll(head);
    // head=deletemiddlenode2(head);
    head=deletemiddlenodeoptimal(head);
    // head =deletemiddlenode(head);
    printll(head);
    return 0;
   }