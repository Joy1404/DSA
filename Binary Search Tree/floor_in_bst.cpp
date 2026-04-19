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

int floorInBST(TreeNode* root, int x){
    int floor=-1;
    while(root!=NULL){
        if(root->data==x){
            return root->data;
        }
        if(root->data<x){
            floor=root->data;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return floor;
}

int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    int x=5;
    int result=floorInBST(root,x);
    if(result!=-1){
        cout<<"Floor of "<<x<<" is "<<result<<endl;
    }
    else{
        cout<<"Floor of "<<x<<" is not found"<<endl;
    }
    return 0;
}   