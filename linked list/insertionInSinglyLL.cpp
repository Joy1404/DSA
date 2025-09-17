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
 node* insertatHead(node* head,int val){
     // return new node(val,head); // also valid
    if(head==NULL){
        node* temp = new node(val);
        return temp;
    }
    node* temp = new node(val,head);
    return temp;
 }
 node* insertatTail(node* head,int val){
    if(head==NULL){
        // return new node(val); // also valid
        node* temp = new node(val);
        return temp;
    }
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    node* toadd = new node(val);
    temp->next=toadd;
    return head;
 }
 node* insertatk(node* head,int k,int val){
    if(head==NULL){
        if(k==1){
            return new node(val);
        }
        return NULL;
    }
    if(k==1){
        node* temp=new node(val,head);
        return temp;

    }
    node* temp = head;
    int cnt=0;
   while(temp!=NULL)
    {
        cnt++;
        if(cnt==k-1){
        node* toadd = new node(val); // also valid node* toadd = new node(val,temp->next);
        toadd->next= temp->next;
        temp->next=toadd;
        break;
        }
        temp=temp->next;
        if(temp==NULL){
            return head; //k is more than length of ll
        }
    }
    return head;
}
 node* insertbeforeval(node* head,int el,int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        node* temp=new node(el,head);
        return temp;

    }
    node* temp = head;
   while(temp->next!=NULL)
    {
        if(temp->next->data==val){
        node* toadd = new node(el); // also valid node* toadd = new node(el,temp->next);
        toadd->next= temp->next;
        temp->next=toadd;
        break;
        }
        temp=temp->next;
    }
    return head;
}
node* insertafterval(node* head,int el,int val){
    if(head==NULL){
        return NULL;
    }
    node* temp = head;
   while(temp!=NULL)
    {
        if(temp->data==val){
        node* toadd = new node(el); // also valid node* toadd = new node(el,temp->next);
        toadd->next= temp->next;
        temp->next=toadd;
        break;
        }
        temp=temp->next;
    }
    return head;
}
 int main(){
vector<int> arr={2,3,4,5};
node* head =convertArrToLl(arr);
// head=insertatHead(head,1);
// head=insertatTail(head,6);
// head=insertatk(head,1,20);
// head=insertatk(head,5,30);
// head=insertatk(head,3,10);
// head=insertatk(head,6,100);
head=insertbeforeval(head,100,5);
head=insertafterval(head,200,3);
printll(head);
 }