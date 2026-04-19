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

TreeNode* deleteNode(TreeNode* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data>key){
        root->left=deleteNode(root->left,key);
    }
    else if(root->data<key){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        TreeNode* temp=root->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
// method 2
TreeNode* findLastRight(TreeNode* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
TreeNode* helper(TreeNode* root){
    if(root -> left == NULL) return root->right;
    if(root -> right == NULL) return root->left;
    TreeNode* rightchild = root -> right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight -> right = rightchild;
    return root -> left;
} 
TreeNode* deleteNode(TreeNode* root, int key){
    if(root== NULL) return NULL;
    if(root->data == key) return helper(root);
    TreeNode* dummy = root;
    while(root!=NULL){
        if(root->data>key){
            if( root->left != NULL && root->left->data==key){
                root->left=helper(root->left);
                break;
            }
            root=root->left;
        }
        else{
            if(root->right != NULL && root->right->data==key){
                root->right=helper(root->right);
                break;
            }
            root=root->right;
        }
    }
    return dummy;
}

int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    int key=2;
    TreeNode* result=deleteNode(root,key);
    if(result!=NULL){
        cout<<"Element deleted successfully"<<endl;
    }
    else{
        cout<<"Element not deleted"<<endl;
    }
    return 0;
}   