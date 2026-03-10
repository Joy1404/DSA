#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
   class Node{
    public:
     int key,val;
     Node*prev;
     Node*next;
     Node(int k,int v){
        key=k;
        val=v;
        prev=next=NULL;
    }
   };
   Node*head =new Node(-1,-1);
   Node*tail =new Node(-1,-1);
   unordered_map<int,Node*>m;
   int cap;
   void addnodeafterhead(Node* newnode){
    Node* temp = head->next;
    newnode->next=temp;
   newnode->prev=head;
   head->next=newnode;
    temp->prev=newnode;
   }
   void delnode(Node* delnode){
    Node* delprev = delnode->prev;
    Node* delnext = delnode->next;
    delprev->next=delnext;
    delnext->prev=delprev;
   }
    LRUCache(int capacity) {
        cap=capacity;
        m.clear();
        head->next=tail;
        tail->prev=head;
        
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* ansnode =m[key];
        delnode(ansnode);
        addnodeafterhead(ansnode);
        return ansnode->val;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* node =m[key];
            node->val=value;
            delnode(node);
            addnodeafterhead(node);
             return;
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        Node* newnode = new Node (key,value);
        m[key]=newnode;
        addnodeafterhead(newnode);
        
    }
};
int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl;
    obj->put(3,3);
    cout<<obj->get(2)<<endl;
    obj->put(4,4);
    cout<<obj->get(1)<<endl;
    cout<<obj->get(3)<<endl;
    cout<<obj->get(4)<<endl;
    return 0;
}
