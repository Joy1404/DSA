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

TreeNode* insertInBST(TreeNode* root, int val){
    if(root==NULL){
        return new TreeNode(val);
    }
    // if(root->data>val){
    //     root->left=insertInBST(root->left,val);
    // }
    // else{
    //     root->right=insertInBST(root->right,val);
    // }
    // return root;
    TreeNode* curr = root;
    while(true){
        if(curr->data>val){
            if(curr->left==NULL){
                curr->left=new TreeNode(val);
                break;
            }
            curr=curr->left;
        }
        else{
            if(curr->right==NULL){
                curr->right=new TreeNode(val);
                break;
            }
            curr=curr->right;
        }
    }
    return root;
}

int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    int val=5;
    TreeNode* result=insertInBST(root,val);
    if(result!=NULL){
        cout<<"Element inserted successfully"<<endl;
    }
    else{
        cout<<"Element not inserted"<<endl;
    }
    return 0;
}       