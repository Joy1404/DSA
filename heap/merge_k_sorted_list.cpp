#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
// merge function to merge two sorted linked lists
// approach: at first we create a dummy node to store the merged linked list and a tail pointer to keep track of the last node in the merged linked list.
// then we iterate through both linked lists and compare the data of the current nodes of both linked lists.
// we append the smaller node to the merged linked list and move the corresponding pointer to the next node.
// finally, we append the remaining nodes of the non-empty linked list to the merged linked list and return the head of the merged linked list.
Node* merge(Node* head1,Node* head2){
      Node* head = new Node(0);
      Node* tail = head;
      while(head1&& head2){
          if(head1->data<=head2->data){
              tail->next = head1;
              head1= head1->next;
              tail=tail->next;
              tail-> next = NULL;
          }else{
              tail->next = head2;
              head2=head2->next;
              tail = tail->next;
              tail->next=NULL;
          }
      }
      if(head1) tail->next = head1;
      else tail->next= head2;
      return head->next;
  }
  // time complexity: O(N*k2) where N is the average number of nodes in each linked list and k is the number of linked lists.
  // space complexity: O(1) as we are not using any extra space.
    Node* mergeKListsbrute(vector<Node*>& arr) {
        // code here
        int k = arr.size();
        Node* head = arr[0];
        for(int i=1;i<k;i++) head = merge(head,arr[i]);
        return head;
        
    }
     void mergesort(vector<Node*>&arr,int st , int end){
      if(st>=end) return;
      int mid = st+(end-st)/2;
      mergesort(arr,st,mid);
      mergesort(arr,mid+1,end);
     arr[st]= merge(arr[st],arr[mid+1]);
  }
  // time complexity: O(N*k log k) where N is the average number of nodes in each linked list and k is the number of linked lists.
  // space complexity: O(1) as we are not using any extra space.
    Node* mergeKListsbetter(vector<Node*>& arr) {
        int k = arr.size();
        mergesort(arr,0,k-1);
        return arr[0];
        
    }
    // using min heap
    // time complexity: O(N*k logk) where N is the average number of nodes in each linked list and k is the number of linked lists.
    // space complexity: O(k) as we are using a min heap to store the nodes
    class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
    };
    Node* mergeKListsheap(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        for(auto head: arr){
            if(head) minHeap.push(head);
        }
        Node* head = new Node(0);
        Node* tail = head;
        while(!minHeap.empty()){
            Node* top = minHeap.top();
            minHeap.pop();
            tail->next = top;
            tail = tail->next;
            if(top->next) minHeap.push(top->next);
        }
        return head->next;
    }
int main(){
    vector<Node*> lists;
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);
    lists.push_back(list1);
    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);
    lists.push_back(list2);
    Node* list3 = new Node(2);
    list3->next = new Node(6);
    lists.push_back(list3);
    Node* mergedHead = mergeKListsheap(lists);
    Node* curr = mergedHead;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}