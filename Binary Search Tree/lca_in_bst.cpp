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
TreeNode* LCA(TreeNode* root,int p,int q){
    if(root==NULL){
        return NULL;
    }
    // both are smaller than root so go to left subtree
    if(root->data<p && root->data<q){
        return LCA(root->right,p,q);
    }
    // both are greater than root so go to right subtree
    if(root->data>p && root->data>q){
        return LCA(root->left,p,q);
    }
    // this is the case when we have found the LCA i.e one is in left subtree and other is in right subtree
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
    int p=2,q=3;
    TreeNode* result=LCA(root,p,q);
    cout<<"The LCA of "<<p<<" and "<<q<<" is: "<<result->data<<endl;
    return 0;
}