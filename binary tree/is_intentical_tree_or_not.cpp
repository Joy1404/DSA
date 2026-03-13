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
// approach: we will check if the data of the current nodes of both trees are equal and then we will check for the left and right subtrees recursively.
bool isIdentical(TreeNode* p, TreeNode* q){
    if(p==NULL || q==NULL){
        return p==q;
    }
    return (p->data==q->data) && isIdentical(p->left,q->left) && isIdentical(p->right,q->right);
}
int main(){
    TreeNode* root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    TreeNode* root2=new TreeNode(1);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);
    if(isIdentical(root1,root2)){
        cout<<"The two trees are identical."<<endl;
    }
    else{
        cout<<"The two trees are not identical."<<endl;
    }
    return 0;
}