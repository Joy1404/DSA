#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    string url;
    Node* next;
    Node* prev;
    Node(string url){
        this->url=url;
        next=NULL;
        prev=NULL;
    }
};
class Browser{
    Node* currentpage;
    public:
    Browser(string &homepage){
        currentpage=new Node(homepage);
    }
    void visit(string &url){
        Node* newpage=new Node(url);
        currentpage->next=newpage;
        newpage->prev=currentpage;
        currentpage=newpage;
    }
    string back(int steps){
        while(steps-- && currentpage->prev!=NULL){
            currentpage=currentpage->prev;
        }
        return currentpage->url;
    }
    string forward(int steps){
      while(steps){
        if(currentpage->next){
            currentpage=currentpage->next;
        }
        else{
            break;
        }
        steps--;
      }
        return currentpage->url;
    }
};
