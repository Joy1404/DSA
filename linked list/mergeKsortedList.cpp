#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};
Node* convert(vector<int>& arr) {
    Node* head = new Node(0);
    Node* tail = head;
    for (int i = 0; i < arr.size(); i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head->next;
}
Node* mergeTwoList(Node* l1, Node* l2) {
    Node* head = new Node(-1);
    Node* tail = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
         
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1) {
        tail->next = l1;
    }
    if (l2) {
        tail->next = l2;
    }
    return head->next;
}
// we will use a min heap to store the first element of each linked list and then we will pop the minimum element from the heap and add it to the result linked list and then we will push the next element of the popped element to the heap and repeat this process until the heap is empty and return the head of the merged linked list
// time complexity is O(nlogk) where n is the total number of nodes in all the linked list and k is the number of linked list and space complexity is O(k) for the heap
Node* mergekListoptimal(vector<Node*>&lists){
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    for(int i =0;i<lists.size();i++){
        if(lists[i]){
            pq.push({lists[i]->val,lists[i]});
        }
    }
    Node* head = new Node(-1);
    Node* temp = head;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        temp->next = it.second;
        temp = temp->next;
        if(it.second->next){
            pq.push({it.second->next->val,it.second->next});
        }
    }
    return head->next;
}
// we will merge the first two linked list and then we will merge the result with the third linked list and so on until we merge all the linked list and return the head of the merged linked list
Node* mergekListbetter(vector<Node*>&lists){
    Node* head = lists[0];
    for(int  i =1;i<lists.size();i++){
        head = mergeTwoList(head,lists[i]);
    }
    return head;
}
// at first we will store all the values of the linked list in an array and then we will sort the array and then we will convert the array into a linked list and return the head of the linked list
Node* mergekList(vector<Node*>&lists){
    vector<int> arr;
    for(int i =0;i<lists.size();i++){
        Node* temp = lists[i];
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }
    sort(arr.begin(),arr.end());
   Node* newhwad =   convert(arr);   
    return newhwad;
}
int main(){
    vector<Node*> lists;
    vector<int> arr1 = {1,4,5};
    vector<int> arr2 = {1,3,4};
    vector<int> arr3 = {2,6};
    lists.push_back(convert(arr1));
    lists.push_back(convert(arr2));
    lists.push_back(convert(arr3));
    Node* head = mergekListoptimal(lists);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}