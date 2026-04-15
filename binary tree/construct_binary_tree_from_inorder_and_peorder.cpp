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
// time complexity : O(n)
// space complexity : O(n)
// approach :  at first we create a map of inorder traversal to get the index of the root element
// then we use recursion to build the tree  
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    } 
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>& inMap){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot-inStart;
        // for left subtree we will take the left part of the inorder and for preorder we will take the left part of the preorder
        root->left = build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
        // for right subtree we will take the right part of the inorder and for preorder we will take the right part of the preorder
        root->right = build(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
        return root;
    }