#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// function to reverse the linked list
ListNode* reverse(ListNode* head){
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
// Function to check if the linked list is a palindrome
// Time Complexity: O(2n), Space Complexity: O(n)
bool isPalindrome(ListNode* head){
    stack<int> st;
    ListNode* temp = head;
    while(temp!=NULL){
        st.push(temp->val);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->val!=st.top()){
            return false;
        }
        st.pop();
        temp=temp->next;
    }
    return true;
}
// optimal approach
// approach: find the middle of the linked list, reverse the second half of the linked list and then compare both halves
// if both halves are same then it is a palindrome else not
// finally reverse the second half again to restore the original linked list
// Time Complexity: O(2n), Space Complexity: O(1)
bool palindromeoptimise(ListNode* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* newhead=reverse(slow->next);
    ListNode* first = head;
    ListNode* second = newhead;
    while(second!=NULL){
        if(first->val!=second->val){
            reverse(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    return true;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(1);

    if(palindromeoptimise(head)){
        cout<<"It is a palindrome linked list"<<endl;
    }
    else{
        cout<<"It is not a palindrome linked list"<<endl;
    }
    return 0;
}