#include <bits/stdc++.h>
using namespace std;
class node{
public:
  int data;
  node* next;
  node(int data1,node* next1){
    data=data1;
    next=next1;
  }
  node(int data1){
    data=data1;
    next=NULL;
  }
};
   void printll(node* head){
    node* temp = head;
    while (temp != NULL) {  
        cout << temp->data << " ";  // print ll element
        temp = temp->next;
    }
    cout<<"\n";
   }
   node* convertArrToLl(vector<int> arr){
   node* head =new node(arr[0]);
   node* mover =head;
   for (int i = 1; i < arr.size(); i++)
   {
      node* temp= new node(arr[i]);
      mover->next=temp;
      mover=temp; 
   }
   return head;
 }
   node* deleteAtHead(node* head){
    if(head==NULL) return NULL;
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  node* deleteAtTail(node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    node* temp = head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=NULL;
    delete todelete;
    return head;
  }
  node* deletek(node* head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        node* temp = head;
        head=head->next;
        delete temp;
        return  head;
    }
    int cnt=1;
    node*temp=head,*prev=NULL;
    while(temp!=NULL){
        if(cnt==k){
            prev->next=temp->next; // prev->next = prev->next->next
            delete temp;
            break;
        }
        cnt++;
        prev=temp;
        temp=temp->next;
    }
    return head;
  }
  
  node* deleteel(node* head,int el){
    if(head==NULL){
        return head;
    }
    if(head->data==el){
        node* temp = head;
        head=head->next;
        delete temp;
        return  head;
    }
    node*temp=head,*prev=NULL;
    while(temp!=NULL){
        if(temp->data==el){
            prev->next=temp->next; // prev->next = prev->next->next
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
    }
int main(){
vector<int> arr={2,3,4,5};
node* head =convertArrToLl(arr);
head = deleteel(head,5);
printll(head);
}