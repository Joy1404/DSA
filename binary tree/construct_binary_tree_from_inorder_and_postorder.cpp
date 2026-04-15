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
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size()!= postorder.size()) return nullptr;   
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }
    TreeNode* root = build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
        return root;
    } 
    TreeNode* build(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int postStart,int postEnd,map<int,int>& inMap){
        if(postStart>postEnd || inStart>inEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot-inStart;
        // for left subtree we will take the left part of the inorder and for postorder we will take the left part of the postorder
        root->left = build(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,inMap);
        // for right subtree we will take the right part of the inorder and for postorder we will take the right part of the postorder
        root->right = build(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,inMap);
        return root;
    }   