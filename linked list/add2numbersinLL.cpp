#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* t1 = l1, * t2 = l2, * curr = dummy;
    int carry = 0;

    while (t1 != nullptr || t2 != nullptr ) {
        int sum = carry;
        if (t1!= nullptr) {
            sum += t1->data;
        }
        if (t2 != nullptr) {
            sum += t2->data;
        }
       Node* newNode = new Node(sum % 10);
         carry = sum / 10;
         curr->next = newNode;
         curr = curr->next;
         if (t1 != nullptr) t1 = t1->next;
         if (t2 != nullptr) t2 = t2->next;
    }
    if(carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummy->next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    Node* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}