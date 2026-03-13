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

vector<vector<int>> zigZagTraversal(TreeNode* root){
    vector<vector<int>> result;
    if(root==NULL){
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> level(size);
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            int index=leftToRight?i:(size-1-i);
            level[index]=node->data;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        leftToRight=!leftToRight;
        result.push_back(level);
    }
    return result;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    vector<vector<int>> result=zigZagTraversal(root);
    for(const auto& level:result){
        for(int val:level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}