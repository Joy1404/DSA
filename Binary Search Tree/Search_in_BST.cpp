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

TreeNode* searchInBST(TreeNode* root, int val){
    // if(root==NULL){
    //     return NULL;
    // }
    // if(root->data==val){
    //     return root;
    // }
    // if(root->data>val){
    //     return searchInBST(root->left,val);
    // }
    // return searchInBST(root->right,val);
    while(root!=NULL && root->data!=val){
       root = root->data>val?root->left:root->right;
    }
    return root;
}

int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    TreeNode* result=searchInBST(root,6);
    if(result!=NULL){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}