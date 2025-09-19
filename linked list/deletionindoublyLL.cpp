#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *back;
    node(int data1, node *next1, node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    node(int data1)
    {
        data = data1;
        next = NULL;
        back = NULL;
    }
};
node *convertArrToLl(vector<int> arr)
{
    node *head = new node(arr[0]);
    node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " "; // print ll element
        temp = temp->next;
    }
    cout << endl;
}

node *delete_head(node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    node *temp = head;
    head = head->next;
    head->back = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}
node *delete_tail(node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *newtail = temp->back;
    newtail->next = NULL;
    temp->back = NULL;
    free(temp);
    return head;
}
node *delete_kth_position(node *head, int k)
{
   if(head==NULL) return NULL;
   int count=0;
    node* temp=head;
    while(temp!=NULL){
        count++;
        if(count==k){
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL) return head;
    node* front=temp->next;
    node* prev=temp->back;
    if(prev==NULL && front==NULL){
        free(temp);
        return NULL;
    }
    else if(prev==NULL){
        return delete_head(head);
    }
    else if(front==NULL){
        return delete_tail(head);
    }
    prev->next=front;
    front->back=prev;
    temp->next=temp->back=NULL;
    free(temp);
    return head;
}
void delete_node(node *temp)
{
    node *front = temp->next;
    node *prev = temp->back;
    if (front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}
int main()
{
    vector<int> arr = {2, 3, 5, 4, 5, 5};
    node *head = convertArrToLl(arr);
    //    print(head);
    //   node* head1=delete_head(head);
    //   print(head1);
    // node *tail = delete_tail(head);
    // print(tail);
    // node* kth=delete_kth_position(head,3);
    // print(kth);
       delete_node(head->next);
       print(head);
    return 0;
}