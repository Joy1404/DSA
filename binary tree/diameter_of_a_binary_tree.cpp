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
int maxi = 0;
// Naive approach: O(n^2) time complexity
void  diameter(TreeNode* root) {
    if(root == NULL) return;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    maxi = max(maxi, leftHeight + rightHeight);
    diameter(root->left);
    diameter(root->right);
}
int findiameter(TreeNode* root) {
    diameter(root);
    return maxi;
}
// Optimized approach: O(n) time complexity
int height1(TreeNode* node, int &diameter) {
     if (node == NULL) return 0;
     
     int leftHeight = height1(node->left, diameter);
     int rightHeight = height1(node->right, diameter);
     
     diameter = max(diameter, leftHeight + rightHeight);
     
     return max(leftHeight, rightHeight) + 1;
 };
int diameterOfbinarytree(TreeNode* root){
    int diameter = 0;
    height1(root, diameter);
    return diameter;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    
    cout << "Diameter of the binary tree: " << findiameter(root) << endl;
    
    return 0;
}