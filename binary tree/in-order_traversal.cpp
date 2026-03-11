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
void inOrder(TreeNode* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
vector<int> inOrderTraversal(TreeNode* root){
    vector<int> result;
    if(root==NULL) return result;
    stack<TreeNode*> s;
    TreeNode* curr=root;
    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        result.push_back(curr->data);
        curr=curr->right;
    }
    return result;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    inOrder(root);
    return 0;
}