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
// approach : level order traversal with indexing and each level we find minindex and in the next level its index will be 2*(   cur_id-min_id)+1 and 2*(cur_id-min_id)+2 
int widthOfBinaryTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int maxWidth = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        int minIndex = q.front().second;
        int first,last;
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front().first;
            int cur_id = q.front().second-minIndex;
            q.pop();
            if(i == 0){
                first = cur_id;
            }
            if(i == size - 1){
                last = cur_id;
            }
            maxWidth = max(maxWidth, last - first + 1);
            if(node->left){
                q.push({node->left, 2 * cur_id + 1});
            }
            if(node->right){
                q.push({node->right, 2 * cur_id + 2});
            }
        }
        maxWidth = max(maxWidth, last - first + 1); 
    }
    return maxWidth;
} 
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    cout << widthOfBinaryTree(root) << endl;
    return 0;
}         