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
// we can use a vector to store the path from root to node and return it when we find the target node
// at each node we will check if the current node is the target node, if it is then we will return the path, if not then we will continue to search in the left and right subtree
bool getPath(   TreeNode* root, int target, vector<int>& path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->val);
    if(root->val == target){
        return true;
    }
    if(getPath(root->left, target, path) || getPath(root->right, target, path)){
        return true;
    }
    path.pop_back(); // if we are not able to find the target node in the left and right subtree then we will remove the current node from the path and return false
    return false;
}
// at each node we will check if the current node is the target node, if it is then we will return the path, if not then we will continue to search in the left and right subtree
vector<int> printRootToNode(TreeNode* root, int target){
    vector<int> arr;
    if(root == NULL){
        return arr  ;
    }
    if(root->val == target){
        arr.push_back(root->val);
        return arr;
    }
    getPath(root, target,arr);
    return arr;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> arr = printRootToNode(root, 5);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }   
    return 0;
}   