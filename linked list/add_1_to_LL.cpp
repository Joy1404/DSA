#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// Function to add 1 to the linked list
// Time Complexity: O(3n), Space Complexity: O(1)
// where n is the number of nodes in the linked list
// We can optimize it to O(n) time complexity by using recursion
Node* addOneToLinkedList(Node* head) {
    // Reverse the linked list
    head = reverseList(head);

    // Add 1 to the reversed linked list
    Node* temp = head;
    int carry = 1;
    while (temp != NULL) {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        if (carry == 0) break;
        temp = temp->next;
    }

    // If there is a carry, add a new node
    if (carry > 0) {
        Node* newNode = new Node(carry);
         head = reverseList(head); // Reverse back to original order before adding new node  it is optional
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Reverse the linked list again to restore original order
    head = reverseList(head);
    return head;
}
// optimal solution using recursion
int helper(Node* temp) {
    if (temp == NULL) return 1; // Base case: if we reach the end, return carry 1
    int carry = helper(temp->next); // Recur for the next node
    int sum = temp->data + carry; // Add carry to current node's data
    temp->data = sum % 10; // Update current node's data
    return sum / 10; // Return new carry
}
Node* addOneUtil(Node* head) {
   int newCarry = helper(head);
   if (newCarry) {
       Node* newNode = new Node(newCarry);
       newNode->next = head;
       head = newNode;
   }
   return head;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(8);
    cout << "Original Linked List: ";
    printList(head);
    int carry = 0;
    head = addOneUtil(head);
    cout << "Linked List after adding 1: ";
    printList(head);
    return 0;
}