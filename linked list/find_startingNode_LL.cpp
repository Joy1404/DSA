#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
// brute force approach using map
// time complexity: O(n)
// space complexity: O(n)
//approach: use a map to store the nodes we have visited
// if we encounter a node that is already in the map, we have found the starting point of the loop
// else we keep adding the nodes to the map
// if we reach the end of the linked list, we return NULL
Node* startingpoint(Node* head){
    map<Node*,int> mp;
    Node* temp = head;
    while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            return temp;
        }
        mp[temp]++;
        temp = temp->next;
    }
  
  return NULL;
}
//optimal approach: Floyd's Cycle Detection Algorithm
// time complexity: O(n)
// space complexity: O(1)
// approach: use two pointers, slow and fast
// move slow pointer by one and fast pointer by two
// if they meet, there is a loop
// to find the starting point, move one pointer to the head and keep the other at the meeting point
// move both pointers by one, the point where they meet is the starting point of the loop
// if they do not meet, return NULL
Node* startingpoint_optimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
          slow = head;
          while(slow!=fast){
              slow = slow->next;
              fast = fast->next;
          }
            return slow;
        }
    }
    return NULL;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // creating a loop
    Node* startNode = startingpoint_optimal(head);
    if(startNode!=NULL){
        cout<<"Starting point of the loop is: "<<startNode->data<<endl;
    }
    else{
        cout<<"No loop detected"<<endl;
    }
    return 0;
}