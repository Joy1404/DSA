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
int height(TreeNode* root) {
    if(root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}
// Naive approach: O(n^2) time complexity
// This approach calculates the height of each subtree for every node, leading to redundant calculations.
bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if(abs(leftHeight - rightHeight) > 1) return false;
    
    return isBalanced(root->left) && isBalanced(root->right);
}
int dfsHeight(TreeNode* root) {
    if(root == NULL) return 0;
    
    int leftHeight = dfsHeight(root->left);
    if(leftHeight == -1) return -1; // Left subtree is not balanced
    
    int rightHeight = dfsHeight(root->right);
    if(rightHeight == -1) return -1; // Right subtree is not balanced
    
    if(abs(leftHeight - rightHeight) > 1) return -1; // Current node is not balanced
    
    return max(leftHeight, rightHeight) + 1; // Return height of the current node
}
// Optimized approach: O(n) time complexity
// This approach calculates the height of each subtree while checking for balance, avoiding redundant calculations.
bool isBalancedOptimized(TreeNode * root){
    return dfsHeight(root) != -1;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    
    if(isBalancedOptimized(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }
    
    return 0;
}