#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
    Node* convertArrToLl(vector<int> arr){
    Node* head =new Node(arr[0]);
    Node* mover =head;
    for (int i = 1; i < arr.size(); i++)
    {
       Node* temp= new Node(arr[i]);
       mover->next=temp;
       mover=temp; 
    }
    return head;
  }
  //optimized approach
  // time complexity = O(n+m) , space complexity = O(1)
  // where n and m are number of nodes in both linked list respectively
  // approach : use two pointers to traverse both linked list and compare the data at each node and link the smaller node to the merged linked list
  Node* mergeTwoSortedLLOptimized(Node* head1 , Node* head2){
    Node* dummyNode = new Node(-1);
    Node* t1 = head1;
    Node* t2 = head2;
    Node* temp = dummyNode;
    while(t1!=NULL && t2!=NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
   if(t1!=NULL){
        temp->next = t1;
    }
    if(t2!=NULL){
        temp->next = t2;
    }
    return dummyNode->next;
  }
  // brute force approach
  // time complexity = O(nlogn) , space complexity = O(n)
  // where n is total number of nodes in both linked list
  // appraoch : store all elements of both linked list in a vector , sort the vector and convert it back to linked list
Node* mergetwosortedll(Node* head1 , Node*head2){
    vector<int>v;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=NULL){
        v.push_back(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        v.push_back(temp2->data);
        temp2 = temp2->next;
    }
    sort(v.begin(),v.end());
    Node* head = convertArrToLl(v);
    return head;
}
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {2,4,6,8};
    Node* head1 = convertArrToLl(arr1);
    Node* head2 = convertArrToLl(arr2);
    Node* mergedhead = mergetwosortedll(head1,head2);
    Node* mergedheadOptimized = mergeTwoSortedLLOptimized(head1,head2);
    display(mergedheadOptimized);
    display(mergedhead);
    return 0;
}