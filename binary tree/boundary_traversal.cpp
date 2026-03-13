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
void leftBoundary(TreeNode* root,vector<int>& ans){
    TreeNode* curr=root->left;
    while(curr){
        if(curr->left || curr->right) ans.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}
void rightBoundary(TreeNode* root,vector<int>& ans){
    TreeNode* curr=root->right;
    vector<int> temp;
    while(curr){
        if(curr->left || curr->right) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}
void leafNodes(TreeNode* root,vector<int>& ans){
    if(!root) return;
    if(!root->left && !root->right) ans.push_back(root->data);
    leafNodes(root->left,ans);
    leafNodes(root->right,ans);
}
// approach: we will first traverse the left boundary and add the nodes to the answer vector, then we will traverse the leaf nodes and add them to the answer vector, finally we will traverse the right boundary and add the nodes to the answer vector in reverse order.
vector<int> boundaryTraversal(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    ans.push_back(root->data);
    leftBoundary(root,ans);
    leafNodes(root,ans);
    rightBoundary(root,ans);
    return ans;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    vector<int> ans=boundaryTraversal(root);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}