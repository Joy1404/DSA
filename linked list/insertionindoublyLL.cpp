#include <iostream>
#include <vector>
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
    if (arr.size() == 0)
        return NULL;
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

node *insert_before_head(node *head, int val)
{
    node *temp = new node(val, head, nullptr);
    if( head != NULL )
     head->back = temp;
    return temp;
}
node *insert_before_tail(node *head, int val)
{
    if (head == NULL)
        return new node(val, NULL, nullptr);
    if( head->next == NULL )
    {
       return insert_before_head(head,val);
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *prev=temp->back;
    node *newnode = new node(val, temp, prev);
    prev->next = newnode;
    temp->back = newnode;
    return head;
}
node *insert_before_kth_position(node *head, int k, int val)
{
   if(k==1){
       return insert_before_head(head,val);
   }
    node *temp = head;
    int count = 0;
    while (temp != NULL){
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    if(temp==NULL) return head;
    node *prev = temp->back;
    node *newnode = new node(val, temp, prev);
    prev->next = newnode;
    temp->back = newnode;
    return head;
}

void insert_before_node(node *temp, int val)
{
    node *prev = temp->back;
    node *newnode = new node(val, temp, prev);
    prev->next = newnode;
    temp->back = newnode;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    node *head = convertArrToLl(arr);
    // print(head);
    //   node* head1 = insert_head(head,9);
    //   print(head1);
      node* head1 = insert_before_tail(head,9);
      print(head1);
    //   node* head1 = insert_kth_position(head,6,100);
    //   print(head1);
    // insert_node(head->next->next,100);
    // print(head);
    return 0;
}