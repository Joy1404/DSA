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
// approach: traverse the linked list and whenever we find a node with the key value, we delete it by adjusting the pointers of the previous and next nodes accordingly.
// if the node to be deleted is the head node, we update the head pointer.
// finally, we return the updated head pointer.
Node* deleteoccurances(Node* head, int key){
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data==key){
            if(curr==head){
                Node* todelete = head;
                head=head->next;
                delete todelete;
            }
            Node* nextnode = curr->next;
            Node* prevnode = curr->prev;
            if(nextnode!=NULL){
                nextnode->prev = prevnode;
            }
            if(prevnode!=NULL){
                prevnode->next = nextnode;
            }
            delete curr;
            curr = nextnode;

        }
        else{
            curr=curr->next;
        }
    }
   return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;

    int key = 2;
    head = deleteoccurances(head, key);

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}