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
Node* findmiddle(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* merge(Node* lefthead,Node* righthead){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(lefthead!=NULL && righthead!=NULL){
        if(lefthead->data<righthead->data){
            temp->next=lefthead;
            lefthead=lefthead->next;
        }
        else{
            temp->next=righthead;
            righthead=righthead->next;
        }
        temp=temp->next;
    }
    if(lefthead!=NULL){
        temp->next=lefthead;
    }
    if(righthead!=NULL){
        temp->next=righthead;
    }
    return dummyNode->next;
}
// we will use merge sort to sort the linked list. we will find the middle of the linked list and then we will sort the left half and right half of the linked list and then we will merge the two halves.
// time complexity: O(nlogn) and space complexity: O(1)
Node* sortoptimal(Node* head){
    if(head==NULL|| head->next==NULL){
        return head;
    }
    Node* middle = findmiddle(head);
    Node* lefthead = head;
    Node* righthead = middle->next;
    middle->next=NULL;
    lefthead=sortoptimal(lefthead);
    righthead=sortoptimal(righthead);
    Node* finalhead=merge(lefthead,righthead);
    return finalhead;
}
// at first we will store the data of the linked list in a vector and then we will sort the vector and then we will update the linked list with the sorted data.
// time complexity: O(nlogn) and space complexity: O(n)
Node* sort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp=head;
    vector<int> v;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    temp=head;
    int i=0;
    while(temp!=NULL){
        temp->data=v[i];
        i++;
        temp=temp->next;
    }
    return head;
}
int main(){
    Node* head=new Node(4);
    head->next=new Node(2);
    head->next->next=new Node(1);
    head->next->next->next=new Node(3);
    head=sortoptimal(head);
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}