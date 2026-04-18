#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
// method 1: using recursion
TreeNode* pred = NULL;
void flatten(TreeNode* root){
    if(root == NULL) return;
    flatten(root->right);
    flatten(root->left);
    root->right = pred;
    root->left = NULL;
    pred = root;
} 
// method 2: using morris traversal
void flatten(TreeNode* root){
    TreeNode* curr=root;
    while(curr!=NULL){
        if(curr->left!=NULL){
            TreeNode* pred=curr->left;
           while(pred->right) pred = pred->right;
           pred->right = curr->right;
           curr->right = curr->left;
           curr->left = NULL;
        } 
        curr = curr->right;
    }     
}
// method 3: using stack
void flatten(TreeNode* root){
    if(root == NULL) return;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
        if(!s.empty()) curr->right = s.top();
        curr->left = NULL;
    }   
} 
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    flatten(root);
    return 0;
}   