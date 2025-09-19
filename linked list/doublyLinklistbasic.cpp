#include<bits/stdc++.h>
using namespace std;
class node{
public:
  int data;
  node* next;
  node* back;
  node(int data1,node* next1,node* back1){
    data=data1;
    next=next1;
    back=back1;
  }
  node(int data1){
    data=data1;
    next=NULL;
    back=NULL;
  }
};
    node* convertArrToLl(vector<int> arr){
    node* head =new node(arr[0]);
    node* prev =head;
    for (int i = 1; i < arr.size(); i++)
    {
       node* temp= new node(arr[i],NULL,prev);
       prev->next=temp;
       prev=temp; 
    }
    return head;
  }
  void printll(node* head){
    node* temp = head;
    while (temp != NULL) {  
        cout << temp->data << " ";  // print ll element
        temp = temp->next;
    }
  }

int main(){
vector<int> arr={2,3,4,5};
node* head =convertArrToLl(arr);
printll(head);
return 0;
    }