#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;
    Node(int val){
        data = val;
        next = NULL;
        child = NULL;
    }
};
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->child;
    }
    cout<<endl;
}
// to convert the vector to a linked list
Node* convert(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        temp->child = new Node(arr[i]);
        temp = temp->child;
    }
    return head;
}
// optimal approach to flatten the linked list
// at first we will flatten the linked list from the right side and then we will merge the flattened linked list with the current linked list
Node* meerge(Node* list1, Node* list2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(list1!=NULL && list2!=NULL){
        if(list1->data < list2->data){
            temp->child = list1;
            temp = temp->child;
            list1 = list1->child;
        }
        else{
            temp->child = list2;
            temp = temp->child;
            list2 = list2->child;
        }
        temp->next = NULL;
    }
    if(list1!=NULL){
        temp->child = list1;
    }
    else{
        temp->child = list2;
    }
    return dummy->child;
    // at the end we will return the child of the dummy node because the dummy node is just a placeholder and it does not contain any data
} Node* flattenoptimal(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mergehead = flattenoptimal(head->next);
    head = meerge(head, mergehead);
    return head;
}
// at first we will store all the elements of the linked list in a vector and then sort the vector and then convert the vector to a linked list
// time complexity is O(nlogn) and space complexity is O(n) whre n = number of nodes in the linked list
Node* flatten(Node* head){
    vector<int>arr;
    Node* temp = head;
    while(temp!=NULL){
        Node *t2 = temp;
        while(t2!=NULL){
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    Node* newhead = convert(arr);
    return newhead;
}
int main(){
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);
    head->next->child = new Node(20);
    head->next->child->child = new Node(22);
    head->next->child->child->child = new Node(50);
    head->next->next->child = new Node(35);
    head->next->next->child->child = new Node(40);
    head->next->next->child->child->child = new Node(45);
    cout<<"Flattened List: "<<endl;
    Node* flatHead = flattenoptimal(head);
    printList(flatHead);
}