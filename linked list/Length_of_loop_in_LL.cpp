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
// brute force 
//time complexity : O(2N* map) , space complexity : O(N)
// approach : we will use map to store the visited nodes with their visit count
// when we visit a node again we will return the difference of current count and stored count
// this difference will be the length of the loop
 int findLoopLenght (node* head){
  map<node*,int> visited;
  node* temp=head;
  int count=1;
  while(temp!=NULL){
    if(visited.find(temp)!=visited.end()){
        return count - visited[temp];
    }
    visited[temp]=count;
    count++;
    temp=temp->next;
  }
  return 0;
 }
 //optimal approach
 //time complexity : O(N) , space complexity : O(1)
 // approach : we will use floyds cycle detection algorithm to detect the loop
 // once loop is detected we will keep one pointer at meeting point and move other pointer
 // until it meets the first pointer again counting the nodes in between
 // this count will be the length of the loop
 
 int countLoopLength(node* slow,node* fast){
    int count=1;
    fast=fast->next;
    while(slow!=fast){
        count++;
        fast=fast->next;
    }
    return count;
 }
 int findLoopLengthOptimal(node* head){
    node* slow=head;
    node* fast=head;
    // first we will detect the loop using floyds cycle detection algorithm
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            // loop detected now we will count the length of the loop
            //  int loop_length=1;
            // node* temp=slow;
            // while(temp->next!=slow){
            //     loop_length++;
            //     temp=temp->next;
            // }
            // return loop_length;
           return countLoopLength(slow,fast);
        }
    }
    return 0; // no loop
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
    head->next->next->next->next->next=head->next->next; // creating a loop for testing
    // printll(head); // this will run infinitely due to loop
    cout<<"Length of loop (brute force): "<<findLoopLenght(head)<<"\n";
    cout<<"Length of loop (optimal): "<<findLoopLengthOptimal(head)<<"\n";
    return 0;
   }