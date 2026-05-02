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


bool isValidBST(TreeNode* root) {
    return isvalid(root,LLONG_MIN,LLONG_MAX);
}
bool isvalid(TreeNode* root,long long min,long long max){
    if(root==NULL){
        return true;
    }
    if(root->data<=min || root->data>=max){
        return false;
    }
    return isvalid(root->left,min,root->data) && isvalid(root->right,root->data,max);
}
int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    if(isValidBST(root)){
        cout<<"The tree is a valid BST"<<endl;
    }else{
        cout<<"The tree is not a valid BST"<<endl;
    }
    return 0;
}