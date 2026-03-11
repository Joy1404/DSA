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
void preOrder(TreeNode* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
vector<int> preOrderTraversal(TreeNode* root){
    vector<int> result;
    if(root==NULL) return result;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* node=s.top();
        s.pop();
        result.push_back(node->data);
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
    return result;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    preOrder(root);
    return 0;
}