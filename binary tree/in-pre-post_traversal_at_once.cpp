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
void preInpost(TreeNode * root){
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    vector<int> pre, in, post;
    if(root==NULL) return;
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL) st.push({it.first->left,1});
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL) st.push({it.first->right,1});
        }
        else{
            post.push_back(it.first->data);
        }
    }
    cout<<"Preorder Traversal: ";
    for(auto it:pre) cout<<it<<" ";
    cout<<"\nInorder Traversal: ";
    for(auto it:in) cout<<it<<" ";
    cout<<"\nPostorder Traversal: ";
    for(auto it:post) cout<<it<<" ";
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    preInpost(root);
}