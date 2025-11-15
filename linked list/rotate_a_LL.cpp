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
Node* findNthNode(Node* temp, int k){
    int cnt =1;
    while(temp!=NULL){
        if(cnt==k){
            return temp;
        }
        cnt++;
        temp = temp->next;
    }
    return NULL;
}
// time complexity: O(N)
// space complexity: O(1)
Node* rotate(Node* head , int k){
    if(head == NULL || head->next == NULL || k==0){
        return head;
    }
    Node* tail = head;
    int len =1;
    while(tail->next!=NULL){
        tail = tail->next;
        len++;
    }
    if(k%len ==0){
        return head;
    }
    k = k%len;
    tail->next = head; //making it circular
    Node* newTail = findNthNode(head, len - k);
    head = newTail->next;
    newTail->next = NULL;
    return head;
}
void display(Node* head){
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
    int k = 4;
    cout<<"Original Linked List: ";
    display(head);
    head = rotate(head, k);
    cout<<"Linked List after rotation by "<<k<<" nodes: ";
    display(head);
    return 0;
}