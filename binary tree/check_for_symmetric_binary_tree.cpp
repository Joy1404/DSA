#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

bool isSymmetric2(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL){
        return true;
    }
    if(left == NULL || right == NULL){
        return left == right;
    }
    return (left->val == right->val) && isSymmetric2(left->left, right->right) && isSymmetric2(left->right, right->left);
}
// approach : at each node we check if the left subtree is a mirror image of the right subtree  if both are mirror images then the tree is symmetric and any point where it fails the tree is not symmetric
// time complexity : O(n)
// space complexity : O(n)  
bool isSymmetric(TreeNode* root){
    if(root == NULL){
        return true;
    }
    return isSymmetric2(root->left, root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    if(isSymmetric(root)){
        cout << "The binary tree is symmetric" << endl;
    }else{
        cout << "The binary tree is not symmetric" << endl;
    }
    return 0;
}
