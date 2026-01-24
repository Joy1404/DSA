#include<bits/stdc++.h>
using namespace std;
// problem statement: check if a binary tree is a max heap
// approach: first we will count the number of nodes in the tree
// then we will check if the tree is a complete binary tree using index based method
// finally we will check if the max heap property is maintained by ensuring each parent node is greater than or equal to its child nodes

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int count(Node* root){
      if(root==NULL) return 0;
      return 1+count(root->left)+count(root->right);
  }
  bool CBT(Node*root, int index, int size){
      if(!root) return true; 
      if(index>=size) return false;
      return CBT(root->left,2*index+1,size) && CBT(root->right,2*index+2,size);
  }
  bool maxheap(Node* root){
      if(root->left){
          if(root->data < root->left->data) return 0;
          if(!maxheap(root->left)) return 0;
      }
      if(root->right){
          if(root->data < root->right->data) return 0;
          return maxheap(root->right);
      }
      return 1;
  }
  // main function to check if binary tree is a max heap
  // time complexity: O(n)
  // space complexity: O(h) where h is the height of the tree due to recursion stack
    bool isHeap(Node* tree) {
        // count no of nodes in tree
        int num = count(tree);
        
        // check CBT
        if(!CBT(tree,0,num)) return 0;
        
        // parent>= childs
        
        return maxheap(tree);
    }

    int main(){
        Node* root = new Node(10);
        root->left = new Node(9);
        root->right = new Node(8);
        root->left->left = new Node(7);
        root->left->right = new Node(6);
        
        if(isHeap(root)){
            cout<<"The binary tree is a max heap"<<endl;
        }else{
            cout<<"The binary tree is not a max heap"<<endl;
        }
        return 0;
    }