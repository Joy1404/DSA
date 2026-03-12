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
int pathsum(TreeNode* root,int &maxi){
    if(root==NULL){
        return 0;
    }
    int leftsum=max(0,pathsum(root->left,maxi));
    int rightsum=max(0,pathsum(root->right,maxi));
    maxi=max(maxi,leftsum+rightsum+root->data);
    return root->data+max(leftsum,rightsum);
}
int maxPathSum(TreeNode* root){
    int maxi=INT_MIN;
    pathsum(root,maxi);
    return maxi;
}
int main(){
    TreeNode* root=new TreeNode(-10);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<maxPathSum(root)<<endl;
}