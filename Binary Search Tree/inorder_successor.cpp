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
TreeNode* inorder_predecessor(TreeNode* root, TreeNode* target){
    TreeNode* pred = NULL;
    while(root){
        if(root->data < target->data){
            pred = root;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return pred;
}
TreeNode* inorder_successor(TreeNode* root,TreeNode* target){
    TreeNode* successor=NULL;
    while(root!=NULL){
        if(root->data<=target->data){
            root=root->right;
        }
        else{
            successor=root;
            root=root->left;
        }
    }
    return successor;
}
int main(){
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(15);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(12);
    root->right->right=new TreeNode(17);
    TreeNode* successor=inorder_successor(root,root->left->right);
    TreeNode* predecessor=inorder_predecessor(root,root->left->right);
    cout<<successor->data<<endl; 
    cout<<predecessor->data<<endl; 
    return 0;
}