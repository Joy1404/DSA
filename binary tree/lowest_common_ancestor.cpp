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
// approach :at first check if the current node is the target node, if it is then we will return the current node, if not then we will continue to search in the left and right subtree and if we find the target node in the left subtree then we will return the left subtree, if we find the target node in the right subtree then we will return the right subtree, if we find the target node in both the subtrees then we will return the current node
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q){
    if(root == NULL){
        return NULL;
    }
    if(root->val == p || root->val == q){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left != NULL && right != NULL){
        return root;
    }
    return left != NULL ? left : right;
}   
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
    path.pop_back();
    return false;
}

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
// approach : at first we will find the path from root to node p and root to node q and then we will compare the two paths and the last common node in both the paths will be the lowest common ancestor of p and q.
int lca(TreeNode* root, int p, int q){
    if(root == NULL){
        return -1;
    }
    vector<int> path1 = printRootToNode(root, p);
    vector<int> path2 = printRootToNode(root, q);
    int i = 0;
    while(i < path1.size() && i < path2.size() && path1[i] == path2[i]){
        i++;
    }
    return path1[i-1];  
   
}   

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << lca(root, 4, 5) << endl;
    cout << lowestCommonAncestor(root, 4, 5)->val << endl;  
    return 0;
}   