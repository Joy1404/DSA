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
// traverse in sorted order and find the kth element
// time complexity O(n) space complexity O(n)
// if kth largest element is asked then print the (n-k+1)th smallest element
vector<int> vec;
void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    vec.push_back(root->data);
    inorder(root->right);
}
int kthSmallest(TreeNode* root, int k) {
    inorder(root);
    return vec[k-1];
}
// using morris inorder traversal
int kthSmallestMorris(TreeNode* root, int k) {
    TreeNode* curr=root;
    int count=0;
    while(curr!=NULL){
        if(curr->left==NULL){   
            count++;
            if(count==k){
                return curr->data;
            }
            curr=curr->right;
        }else{
            TreeNode* temp=curr->left;
            while(temp->right!=NULL && temp->right!=curr){
                temp=temp->right;
            }
            if(temp->right==NULL){
                temp->right=curr;
                curr=curr->left;
            }else{
                temp->right=NULL;
                count++;
                if(count==k){
                    return curr->data;
                }
                curr=curr->right;
            }
        }
    }
    return -1;
}


int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    int k=6;
    int result=kthSmallestMorris(root,k);
    cout<<"The kth smallest element is: "<<result<<endl;
    return 0;
}

