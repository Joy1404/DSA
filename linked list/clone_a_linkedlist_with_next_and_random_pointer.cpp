#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val){
        val = _val;
        next = NULL;
        random = NULL;
    }
};
void insertcopyinBetwwen(Node* head){
    Node* temp = head;
    while(temp){
        Node* nextelement = temp->next;
        Node* copy = new Node(temp->val);
        copy->next = nextelement;
        temp->next = copy;
        temp = nextelement;
    }
}
void assignrandompointer(Node* head){
    Node* temp = head;
    while(temp){
        Node* copy = temp->next;
        if(temp->random){
            copy->random = temp->random->next;
        }else{
            copy->random = NULL;
        }
        temp = temp->next->next;
    }
}
Node* extractcopy(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(temp){
        // creating new list
        res->next = temp->next;
        res= res->next;
        // disconnect and going back to initial state of ll
        temp->next = temp->next->next;
        temp = temp->next;
        
    }
    return dummyNode->next;
}
// this approach is better than the hash map approach as it has O(1) space complexity and O(n) time complexity. we are creating a copy of the linked list and inserting it between the original linked list. then we are assigning the random pointers for the copied nodes and finally we are extracting the copied linked list from the original linked list.
Node* cloneLL(Node* head){
    insertcopyinBetwwen(head);
    assignrandompointer(head);
    return extractcopy(head);
}
// at first we will create a copy of the linked list and store the mapping of original node to copied node in a hash map. then we will assign the next and random pointers for the copied nodes using the hash map.
// time complexity: O(n) and space complexity: O(n)
Node* copyrandomList(Node* head){
    unordered_map<Node*,Node*> mpp;
    Node* temp = head;
    while(temp){
        Node* newNode = new Node(temp->val);
      mpp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while(temp){
        mpp[temp]->next = mpp[temp->next]; // mpp[temp] = copynode
        mpp[temp]->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->random = head->next;
    head->next->random = head;
    Node* clonedHead = cloneLL(head);
    // Print the cloned list to verify
    Node* temp = clonedHead;
    while(temp){
        cout << "Node value: " << temp->val << ", Random value: " << (temp->random ? temp->random->val : -1) << endl;
        temp = temp->next;
    }
    return 0;
}