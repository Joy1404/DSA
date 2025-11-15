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
Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
Node* getkthNode(Node*temp,int k){
    k-=1;
    while(temp!=NULL&& k>0){
        temp = temp->next;
        k--;
    }
    return temp;
}
// time complexity: O(n)
// space complexity: O(1)
// approach: first we will get the kth node from the current node, then we will reverse the linked list from current node to kth node, then we will connect the previous last node to the kth node, then we will move the temp to next of kth node and repeat the process until temp is NULL.
Node* kReverse(Node* head , int k){
    if(head==NULL || head->next==NULL || k<=1){
        return head;
    }
   Node* temp = head;
   Node* prevlast = NULL;
   while(temp!=NULL){
    Node* kthNode = getkthNode(temp,k);
    if(kthNode==NULL){
        if(prevlast!=NULL){
            prevlast->next = temp;
        }
        break;
   }
   Node* nextnode = kthNode->next;
   kthNode->next = NULL;
   reverseLL(temp);
   if(temp==head){
    head = kthNode;
   }
   else{
    prevlast->next = kthNode;
   }
   prevlast = temp;
   temp= nextnode;
   }
    return head;
}
void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    int k = 3;
    cout<<"Original List: ";
    printList(head);
    head = kReverse(head,k);
    cout<<"Reversed in K groups List: ";
    printList(head);
    return 0;
}