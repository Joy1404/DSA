#include<bits/stdc++.h>
using namespace std;
// problem statement: convert a BST to a max heap
// approach: we will do inorder traversal to store the elements in a sorted array
// then we will do postorder traversal to assign the values from the sorted array to the tree nodes
// this will ensure that the max heap property is maintained

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

 void inorder(Node* root, vector<int>&ans){
      if(!root) return;
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
      
  }
  void postorder(Node*root, vector<int>&ans,int &index){
      if(!root) return;
      //left
      postorder(root->left,ans,index);
      // right
      postorder(root->right,ans,index);
      // node
      root->data=ans[index++];
  }
  // main function to convert BST to max heap
  // time complexity: O(n)
  // space complexity: O(n)
    void convertToMaxHeapUtil(Node* root) {
        // inorder traversal
        vector<int>ans;
        inorder(root,ans);
        // post order traversal
        int index =0;
        postorder(root,ans,index);
    }
    int main(){
        Node* root = new Node(4);
        root->left = new Node(2);
        root->right = new Node(6);
        root->left->left = new Node(1);
        root->left->right = new Node(3);
        root->right->left = new Node(5);
        root->right->right = new Node(7);
        
        convertToMaxHeapUtil(root);
        
        // Print the converted max heap using level order traversal
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return 0;
    }
