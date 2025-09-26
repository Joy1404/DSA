#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// reverse linked list using recursion
// time complexity O(L)
// space complexity O(L) (recursion stack)
ListNode* reverseList(ListNode* head) {
    // for empty list or single node list
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
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