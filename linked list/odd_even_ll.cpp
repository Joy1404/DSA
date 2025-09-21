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
//  it is based on the fact that we are storing the values of the nodes in an auxiliary array and then reassigning these values back to the nodes in the desired order.
Node* rearrangeOddEven(Node*& head) {
    if (head == nullptr || head->next == nullptr) return head;
    Node*temp=head;
    vector<int>arr;
    while(temp!=NULL && temp->next!=NULL){
              arr.push_back(temp->data);
               temp=temp->next->next;
    }
     if(temp!=NULL) arr.push_back(temp->data);
    temp=head->next;
     while(temp!=NULL && temp->next!=NULL){
              arr.push_back(temp->data);
               temp=temp->next->next;
    }
     if(temp!=NULL) arr.push_back(temp->data);
    // Rearrange the original list based on the collected values
    temp=head;
    int i=0;
    while(temp!=NULL){
            temp->data=arr[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
// Optimal Approach
// Rearranging the list in a single pass
// Time Complexity: O(n)
// Space Complexity: O(1)
//  it is based on the fact that we are changing the next pointers of the nodes to group odd and even indexed nodes together, rather than creating new nodes or using additional data structures to store values.
 Node* oddEvenList(Node* head) {
         if(head == NULL || head->next == NULL){
            return head;
        }

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next ;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        
        return head;
        
    }

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    oddEvenList(head);

    cout << "Rearranged list: ";
    printList(head);

    return 0;
}