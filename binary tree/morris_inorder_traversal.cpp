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
// approach : at first we find the inorder traversal of the tree
// then we use the morris traversal to find the inorder traversal of the tree
// in morris traversal we use the concept of threaded binary tree to find the inorder traversal of the tree without using any extra space
// in morris traversal we first find the inorder predecessor of the current node and then we make the right child of the inorder predecessor point to the current node and then we move to the left child of the current node and repeat the process until we reach the end of the tree
// time complexity: O(n)
// space complexity: O(1)
vector<int> morrisInorder(TreeNode* root){
    vector<int> ans;
    TreeNode* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            ans.push_back(curr->data);
            curr=curr->right;
        }else{
            TreeNode* pred=curr->left;
            while(pred->right!=NULL && pred->right!=curr){
                pred=pred->right;
            }
            if(pred->right==NULL){
                pred->right=curr;
                curr=curr->left;
            }else{
                pred->right=NULL;
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return ans; 
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<int> ans=morrisInorder(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}   