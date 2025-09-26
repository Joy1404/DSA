#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// brute force approach
// we will first calculate the length of linked list
// then we will traverse the linked list till length-n and remove that node
// time complexity O(L) + O(L-n) = O(2L-n) ~ O(L)
// space complexity O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
  int count=0;
    ListNode* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(count==n){
        ListNode* toDelete=head;
        head=head->next;
        delete toDelete;
        return head;
    }
    temp=head;
   int rest=count-n;
   while(temp!=NULL){

         rest--;
         if(rest==0){
              break;
         }
         temp=temp->next;
   }
    ListNode* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
    return head;
}
//optimized approach
// we will use two pointer approach
// we will move first pointer n steps ahead
// then we will move both pointers one step at a time
// when first pointer reaches the end, second pointer will be at the (L-n)th node
// time complexity O(L)
// space complexity O(1)
ListNode* removeNthFromEndOptimized(ListNode* head, int n) {
   ListNode* fast=head;
   for(int i=0;i<n;i++){
       fast=fast->next;
   }
    if(fast==NULL){
         ListNode* toDelete=head;
         head=head->next;
         delete toDelete;
         return head;
    }
   ListNode* slow=head;
   while(fast->next!=NULL){
       fast=fast->next;
       slow=slow->next;
   }
   ListNode* toDelete=slow->next;
   slow->next=slow->next->next;
   delete toDelete;
   return head;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = removeNthFromEndOptimized(head, 2);

    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}
