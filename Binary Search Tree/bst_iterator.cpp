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
class BSTIterator{
private:
    stack<TreeNode*> st;
    void pushLeft(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root){
        pushLeft(root);
    }
    int next(){
        TreeNode* top=st.top();
        st.pop();
        pushLeft(top->right);
        return top->data;
    }
    bool hasNext(){
        return !st.empty();
    }
};
int main(){
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(15);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(12);
    root->right->right=new TreeNode(18);
    BSTIterator it(root);
    while(it.hasNext()){
        cout<<it.next()<<" ";
    }
    return 0;
}