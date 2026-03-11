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
void postOrder(TreeNode* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right); 
    cout<<root->data<<" ";
}
vector<int> postOrderTraversal1(TreeNode* root){
    vector<int> result;
    if(root==NULL) return result;
    stack<TreeNode*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
       TreeNode* node=s1.top();
        s1.pop();
        s2.push(node);
        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }
    while(!s2.empty()){
        result.push_back(s2.top()->data);
        s2.pop();
    }
    return result;
}
vector<int> postOrderTraversal2(TreeNode* root){
    vector<int> result;
    if(root==NULL) return result;
    stack<TreeNode*> s;
    TreeNode* current=root;
    TreeNode* lastVisited=NULL;
    while(!s.empty() || current!=NULL){
        if(current!=NULL){
            s.push(current);
            current=current->left;
        }
        else{
            TreeNode* temp=s.top()->right;
            if(temp==NULL){
                temp=s.top();
                s.pop();
                result.push_back(temp->data);
                while(!s.empty() && temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    result.push_back(temp->data);
                }
            }
            else{
                current=temp;
            }
        }
    }
    return result;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    postOrder(root);
    vector<int> result1 = postOrderTraversal1(root);
    vector<int> result2 = postOrderTraversal2(root);
    for(int val : result1){
        cout<<val<<" ";
    }    cout<<endl;
    for(int val : result2){
        cout<<val<<" ";
    }    cout<<endl;
    return 0;
}