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
string serialize(TreeNode* root){
    if(root==NULL) return "";
    string s="";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node==NULL){
            s+="#,";
        }else{
            s+=to_string(node->data)+",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}
TreeNode* deserialize(string data){
    if(data.empty()) return NULL;
    stringstream ss(data);
    string val;
    // ss>>val;
    getline(ss,val,',');
    TreeNode* root=new TreeNode(stoi(val));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        getline(ss,val,',');
        if(val=="#"){
            node->left=NULL;
        }else{
            node->left=new TreeNode(stoi(val));
            q.push(node->left);
        }
        getline(ss,val,',');
        if(val=="#"){
            node->right=NULL;
        }else{
            node->right=new TreeNode(stoi(val));
            q.push(node->right);
        }
    }
    return root;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    string s=serialize(root);
    cout<<s<<endl;
    TreeNode* root2=deserialize(s);
    string s2=serialize(root2);
    cout<<s2<<endl;
    return 0;
}