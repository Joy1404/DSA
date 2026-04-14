#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// brute
int countnodes(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}
// function to calculate the height of the left subtree
int leftHeight(TreeNode* root){
    int height = 0;
    while(root){
        height++;
        root = root->left;
    }
    return height;
}
// function to calculate the height of the right subtree
int rightHeight(TreeNode* root){
    int height = 0;
    while(root){
        height++;
        root = root->right;
    }
    return height;
}   
// approach : if left height == right height then the tree is a complete binary tree and the number of nodes is 2^height - 1 and if not then recursively call the function for left and right subtrees and add 1 to the result  
    int countNodesoptimal(TreeNode* root) {
        if (!root) return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);    
        
        if (lh == rh) {
            return (1 << lh) - 1;
        }
        
        return 1 + countNodesoptimal(root->left) + countNodesoptimal(root->right);
    }
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    cout << "Number of nodes in the binary tree: " << countNodesoptimal(root) << endl; 
    return 0;   
}
