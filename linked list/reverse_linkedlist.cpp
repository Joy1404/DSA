#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// reverse linked list in terms of data
// we will use stack to store the values of the linked list
// then we will pop the values from the stack and assign them to the linked list
// time complexity O(L) + O(L) = O(2L) ~ O(L)
// space complexity O(L)
ListNode* reverseListInTermsOfData(ListNode* head){
    ListNode* temp=head;
    stack<int> s;
    while(temp!=NULL){
        s.push(temp->val);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->val=s.top();
        s.pop();
        temp=temp->next;
    }
    return head;
}
// optimal approach
// we will reverse the linked list by changing the next pointers
// time complexity O(L)
// space complexity O(1)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* temp = head;
    while (temp != NULL) {
        ListNode* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head=reverseList(head);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}