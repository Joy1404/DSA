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
bool isvalid(TreeNode* root,long long min,long long max){
    if(root==NULL){
        return true;
    }
    if(root->data<=min || root->data>=max){
        return false;
    }
    return isvalid(root->left,min,root->data) && isvalid(root->right,root->data,max);
}
bool isValidBST(TreeNode* root) {
    return isvalid(root,LLONG_MIN,LLONG_MAX);
}
int size(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+size(root->left)+size(root->right);
}
// brute force go to every node and check if it is bst or not time complexity is O(n^2)
int maxBST(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    if(isValidBST(root)){
        return size(root);
    }
    return max(maxBST(root->left),maxBST(root->right));
}
// optimal
class NodeValue{
    public:
    int maxSize;
    int minNode;    
    int maxNode;
    NodeValue(int size,int min,int max){
        this->maxSize=size;
        this->minNode=min;
        this->maxNode=max;
    }
};
NodeValue largestBSTSubtreeHelper(TreeNode* root){
    // base case - an empty tree is a bst of size 0 and for range checking purposes min value should be greater than any node value and max value should be smaller than any node value
    if(root==NULL){
        return NodeValue(0,INT_MAX,INT_MIN);
    }
    // recursive calls for left and right subtrees
    NodeValue left=largestBSTSubtreeHelper(root->left);
    NodeValue right=largestBSTSubtreeHelper(root->right);
    // check if the current node is the root of a bst
    // if left subtree is bst and right subtree is bst and the root is greater than the maximum element of the left subtree and smaller than the minimum element of the right subtree then the current tree is also a bst
    if(left.maxNode<root->data && right.minNode>root->data){
        return NodeValue(1+left.maxSize+right.maxSize,min(left.minNode,root->data),max(right.maxNode,root->data));
    }
    // if the current tree is not a bst then return the maximum size of the bst in the left and right subtrees
    return NodeValue(max(left.maxSize,right.maxSize),INT_MIN,INT_MAX);
}
int largestBSTSubtree(TreeNode* root){
    return largestBSTSubtreeHelper(root).maxSize;
}
int main(){
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(2);
    root->right=new TreeNode(4);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    cout<<largestBSTSubtree(root)<<endl;
    return 0;
}