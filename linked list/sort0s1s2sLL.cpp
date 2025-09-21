#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
// Brute Force Approach
// Rearranging the list using extra space
// Time Complexity: O(n)
// Space Complexity: O(n)
Node* sort012(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    int cnt0=0, cnt1=0, cnt2=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0) cnt0++;
        else if(temp->data==1) cnt1++;
        else cnt2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(cnt0>0){
            temp->data=0;
            cnt0--;
        }
        else if(cnt1>0){
            temp->data=1;
            cnt1--;
        }
        else{
            temp->data=2;
            cnt2--;
        }
        temp=temp->next;
    }
    return head;
}
// Optimal Approach
// Rearranging the list in a single pass
// Time Complexity: O(n)
// Space Complexity: O(1)
//  it is based on the fact that we are changing the next pointers of the nodes to group 0s, 1s, and 2s together, rather than creating new nodes or using additional data structures to store values.
Node* sort012Optimal(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* zeroD = new Node(-1); // Dummy node for 0s
    Node* oneD = new Node(-1);  // Dummy node for 1s
    Node* twoD = new Node(-1);  // Dummy node for 2s

    Node* zero = zeroD, * one = oneD, * two = twoD;
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = curr;
        } else if (curr->data == 1) {
            one->next = curr;
            one = curr;
        } else {
            two->next = curr;
            two = curr;
        }
        curr = curr->next;
    }

    // Connect the three lists
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = nullptr;

    head = zeroD->next;

    // Free dummy nodes
    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    cout << "Original list: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = sort012Optimal(head);

    cout << "Sorted list: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}