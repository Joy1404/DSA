#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
}; 
void markparents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent_track){
    if(root == NULL) return;
    if(root->left) parent_track[root->left] = root;
    if(root->right) parent_track[root->right] = root;
    markparents(root->left, parent_track);
    markparents(root->right, parent_track);
}
vector<int>distanceK(TreeNode* root, TreeNode* target, int k){
    unordered_map<TreeNode*,TreeNode*>parent_track;
    markparents(root,parent_track);
    queue<TreeNode*>q;
    q.push(target);
    unordered_map<TreeNode*,bool>visited;
    visited[target] = true;
    int curr_level =0;  
    vector<int>ans;
    while(!q.empty()){
        int size = q.size();
        if(curr_level++ == k){
            break;
        }
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parent_track[node] && !visited[parent_track[node]]){
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }   
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);    
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode* target = root->left;
    int k = 2;
    vector<int> ans = distanceK(root, target, k);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}