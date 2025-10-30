#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
// brute force approach
// time complexity: O(n)
// space complexity: O(1)
// if there are two middle nodes, it returns the second middle node
// approach: first count the number of nodes in the linked list
// then traverse again to the middle node and return it
// if there are n nodes, middle node is at (n/2 + 1)th position
// (1-based indexing)
Node *middleBrute(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    int mid = count / 2 + 1;
    temp = head;
   while (temp!=NULL){
    mid=mid-1;
    if(mid==0){
        break;
    }
    temp=temp->next;
   }
    return temp;
}
// Function to find the middle of the linked list
// If there are two middle nodes, it returns the second middle node
// optimal approach using slow and fast pointer
// time complexity: O(n)
// space complexity: O(1)
//approach: maintain two pointers slow and fast
// move slow pointer by one and fast pointer by two
// when fast pointer reaches the end, slow pointer will be at the middle
Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    // head->next->next->next->next->next = new Node(6);
    Node *mid = middle(head);
    cout << "Middle node data (optimal): " << mid->data << endl;
    Node *midBrute = middleBrute(head);
    cout << "Middle node data (brute force): " << midBrute->data << endl;
    return 0;
}