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

int ceilInBST(TreeNode* root, int x){
    int ceil=-1;
    while(root!=NULL){
        if(root->data==x){
            return root->data;
        }
        if(root->data>x){
            ceil=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ceil;
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
    int result=ceilInBST(root,x);
    if(result!=-1){
        cout<<"Ceil of "<<x<<" is "<<result<<endl;
    }
    else{
        cout<<"Ceil of "<<x<<" is not found"<<endl;
    }
    return 0;
}
    