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
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
//optimal approach
// Time Complexity: O(n + m)
// Space Complexity: O(1)
// Explanation: The idea is to use two pointers and traverse both linked lists. When a pointer reaches the end of a list, it is redirected to the head of the other list. If there is an intersection, the pointers will meet at the intersection node after at most 2 passes through the lists.
Node* intersection_optimal(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* a = head1;
    Node* b = head2;
    while(a != b){
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
        if(a == b) return a;
    }
    return a; // or return b, both are same
}
// Function to find intersection point of two linked lists
// using hashing
// Approach: Store the nodes of one linked list in a map and then
// traverse the second linked list to check if any node is present in the map
// If found, that node is the intersection point
// Time Complexity: O(n + m) where n and m are the lengths of the two linked lists
// Space Complexity: O(n) or O(m) depending on which list is stored in the map
Node* intersection(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;
   map<Node*,int>mp;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL){
        mp[temp1]++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        // if(mp[temp2] > 0) return temp2;
        if(mp.find(temp2) != mp.end()) return temp2;
        temp2 = temp2->next;
    }
    return NULL;
}
// better approach:
// 1. Get the lengths of both linked lists
// 2. Calculate the difference in lengths
// 3. Move the pointer of the longer list by the difference in lengths
// 4. Now move both pointers one step at a time until they meet
// 5. The meeting point is the intersection point
// Time Complexity: O(n + m)
// Space Complexity: O(1)
Node* intersection_better(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;
    int len1 = 0, len2 = 0;
    while(temp1 != NULL){
        len1++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        len2++;
        temp2 = temp2->next;
    }
    int diff = abs(len1 - len2);
    temp1 = head1;
    temp2 = head2;
    if(len1 > len2){
        for(int i=0; i<diff; i++){
            temp1 = temp1->next;
        }
    } else {
        for(int i=0; i<diff; i++){
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}
int main(){
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    Node* head2 = new Node(6);
    head2->next = head1->next->next; // intersection at node with value 3
    printList(head1);
    printList(head2);
    Node* interNode = intersection_optimal(head1, head2);
    if(interNode != NULL){
        cout<<"Intersection at node with value: "<<interNode->data<<endl;
    } else {
        cout<<"No intersection"<<endl;
    }
    return 0;
}
