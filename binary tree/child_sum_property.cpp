#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
}; 
void changeTree(TreeNode* root){
    if(root == NULL){
        return;
    }
    int child = 0;
    if(root->left){
        child += root->left->val;
    }
    if(root->right){
        child += root->right->val;
    }
   if(child>=root-> val) root->val = child;
   else{
    if(root->left) root->left->val = root->val;
    if(root->right) root->right->val = root->val;
   }
    changeTree(root->left);
    changeTree(root->right);   
    int total = 0; 
    if(root->left) total += root->left->val;
    if(root->right) total += root->right->val;
    if(root->left || root->right) root->val = total; 
} 
int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    changeTree(root);
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    cout << root->left->left->val << endl;
    cout << root->left->right->val << endl;
    cout << root->right->left->val << endl;
    return 0;
}