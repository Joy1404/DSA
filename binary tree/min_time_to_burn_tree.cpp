#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int findmaxDistance(map<TreeNode*,TreeNode*>&mpp,TreeNode* target){
    queue<TreeNode*>q;
    q.push(target);
    map<TreeNode*,bool>visited;
    visited[target] = true;
    int maxi = 0;
    while(!q.empty()){
        int size = q.size();
        int fl =0;
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                fl= 1;
                visited[node->left] = true;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]){
                fl= 1;
                visited[node->right] = true;
                q.push(node->right);
            }
            if(mpp[node] && !visited[mpp[node]]){
                fl= 1;
                visited[mpp[node]] = true;
                q.push(mpp[node]);
            }
        }
        if(fl) maxi++;
    }   
    return maxi;
}  
TreeNode* bfsTomapParents(TreeNode* root, map<TreeNode*,TreeNode*>&mpp,int start){
    queue<TreeNode*>q;
    q.push(root);
    mpp[root] = NULL;   
    TreeNode* res = NULL;
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->val == start) res = node;
        if(node->left){
            mpp[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            mpp[node->right] = node;
            q.push(node->right);
        }
    }   
    return  res;
} 
int minTimeToBurnTree(TreeNode* root, int start){
    map<TreeNode*,TreeNode*>mpp;
    TreeNode* target = bfsTomapParents(root,mpp,start);
    return findmaxDistance(mpp,target);
} 
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    int start = 4;
    cout<<minTimeToBurnTree(root,start)<<endl;
    return 0;
}