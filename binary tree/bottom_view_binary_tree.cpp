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

vector<int> bottomView(TreeNode* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> bottomNode;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode* node=it.first;
        int line=it.second;
       bottomNode[line]=node->data;
        if(node->left){
            q.push({node->left,line-1});
        }
        if(node->right){
            q.push({node->right,line+1});
        }
    }
    for(auto it:bottomNode){
        ans.push_back(it.second);
    }
    return ans;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<int> ans=bottomView(root);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}