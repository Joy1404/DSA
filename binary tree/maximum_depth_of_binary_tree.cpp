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
int maxdepth(TreeNode* root ){
    if(!root) return 0;
    int leftheight = maxdepth(root->left);
    int rightheight = maxdepth(root->right);
    return 1 + max(leftheight,rightheight);

}
int maxdepthiterative(TreeNode* root ){
    if(root == NULL) return 0;
    queue<TreeNode*> q;
    int count = 0;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        count++;
        while(size--){
            TreeNode* node = q.front();
            q.pop();
            if(node->left) q.push(node -> left);
            if(node->right) q.push(node -> right);
        }
    }
    return count;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    cout<<maxdepthiterative(root);
    return 0;
}