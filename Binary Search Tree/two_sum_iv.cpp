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
    bool reverse = true;
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    int next(){
        TreeNode* top=st.top();
        st.pop();
        if(reverse){
            pushAll(top->left);
        }
        else{
            pushAll(top->right);
        }
        return top->data;
    }
    bool hasNext(){
        return !st.empty();
    }
};
bool twoSumBSToptimal(TreeNode* root,int k){
    BSTIterator nextI(root,false);
    BSTIterator prevI(root,true);
    int nextVal = nextI.next();
    int prevVal = prevI.next();
    while(nextVal<prevVal){
        if(nextVal+prevVal==k){
            return true;
        }
        else if(nextVal+prevVal<k){
            nextVal=nextI.next();
        }
        else{
            prevVal=prevI.next();
        }
    }
    return false;
}
// better approach
void inorderTraversal(TreeNode* root, vector<int>& arr) {
    if (root == NULL) return;

    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}
bool twoSumBST(TreeNode* root,int k){
    vector<int> inorder;
    inorderTraversal(root,inorder);
    int i=0;
    int j=inorder.size()-1;
    while(i<j){
        if(inorder[i]+inorder[j]==k){
            return true;
        }
        else if(inorder[i]+inorder[j]<k){
            i++;
        }
        else{
            j--;
        }
    return false;
}
}
int main(){
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(7);
    int k=9;
    if(twoSumBSToptimal(root,k)){
        cout<<"Two sumBST Found"<<endl;
    }
    else{
        cout<<"Two sumBST Not Found"<<endl;
    }
    return 0;
}
