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
class Solution{
    private:
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* second=NULL;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(prev!=NULL && prev->data>root->data){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                second=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    public:
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        first=NULL;
        middle=NULL;
        second=NULL;
        inorder(root);
        if(first!=NULL && second!=NULL){
            swap(first->data, second->data);
        }
        else if(first!=NULL && middle!=NULL){
            swap(first->data, middle->data);
        }
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    s.recoverTree(root);
    return 0;
}