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
class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void display(){
        Node* curr = head;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
  // brute force in terms of data swapping
  void reverse(){
        if(head == NULL) return;
        Node* temp=head;
        stack<int>s;
        while(temp!=NULL){
            s.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        while(!s.empty()){
            temp->data=s.top();
            s.pop();
            temp=temp->next;
        }
    }
    // optimal approach in terms of pointer manipulation
    // TC: O(n) SC: O(1)
    // only change the next and prev pointer of each node
    Node* reverseOptimal(){
        if(head == NULL || head->next == NULL) return head;
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL){
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
        if(prev != NULL){
           return prev->prev;
        }
        return head;
    }
};
int main(){
    DoublyLinkedList dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);
    dll.insert(5);
    cout << "Original List: ";
    dll.display();
    dll.head = dll.reverseOptimal();
    cout << "Reversed List: ";
    dll.display();
    return 0;
}