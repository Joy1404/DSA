#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
// time complexity: O(n)
// space complexity: O(1)
// approach: traverse the linked list and for each node, check if the next node has the same value. If it does, delete the next node and update the pointers accordingly.
// continue this until the next node has a different value.
// finally return the head of the modified linked list.
Node* removeDuplicates(Node* head){
    Node* temp =head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextnode = temp->next;
        while(nextnode!=NULL && nextnode->data == temp->data){
            Node* todelete = nextnode;
            nextnode = nextnode->next;
            delete todelete;
        }
        temp->next = nextnode;
        if(nextnode!=NULL){
            nextnode->prev = temp;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->prev = head->next->next->next;

    head = removeDuplicates(head);

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}