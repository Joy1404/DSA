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

int main(){
vector<int> arr={2,3,4,5};
node* head =convertArrToLl(arr);
int count=0;
 node* temp = head;
    while (temp != NULL) {  
      count++;         // count ll length
        cout << temp->data << " ";  // print ll element
        temp = temp->next;
    }
    int ans=0;
 node* tempo = head;
     while (tempo != NULL) {   // search an element in the ll
       if(tempo->data==5) ans= 1;
        tempo = tempo->next;
    }
   cout<<"\n";
   cout<<count<<endl;
   cout<<ans;
}