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
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> result;
    if(root==NULL) return result;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->data);
        }
        result.push_back(level);
    }
    return result;
}
void levelorder (TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<vector<int>> result=levelOrder(root);
    for(auto level:result){
        for(auto val:level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<"Level order traversal: ";
    levelorder(root);
    return 0;
}