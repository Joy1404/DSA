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

void recursion(TreeNode* root,int level,vector<int>& ans){
    if(root==NULL) return;
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    recursion(root->right,level+1,ans);
    recursion(root->left,level+1,ans);
}
// approach : we will do pre order traversal and at each level we will push the first node of that level in the ans vector. and we will first traverse the right subtree and then left subtree because we want the right view of the tree. 
// if we want the left view of the tree then we will first traverse the left subtree and then right subtree.
// time complexity : O(n) where n is the number of nodes in the tree.
vector<int> rightView(TreeNode* root){
    vector<int>ans;
    recursion(root,0,ans);
    return ans;
}
// approach : we will do level order traversal and at each level we will push the last node of that level in the ans vector.
vector<int> rightView(TreeNode* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int line=it.second;
            if(i==size-1){
                ans.push_back(node->data);
            }
            if(node->left){
                q.push({node->left,line+1});
            }
            if(node->right){
                q.push({node->right,line+1});
            }
        }
    }
    return ans;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<int> ans=rightView(root);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}