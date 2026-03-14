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
// approach: we will do level order traversal and keep track of the horizontal distance of each node from the root. We will use a map to store the first node at each horizontal distance. Finally, we will return the values in the map in order of their keys.
vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> topNode;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode* node=it.first;
        int line=it.second;
        if(topNode.find(line)==topNode.end()){
            topNode[line]=node->data;
        }
        if(node->left){
            q.push({node->left,line-1});
        }
        if(node->right){
            q.push({node->right,line+1});
        }
    }
    for(auto it:topNode){
        ans.push_back(it.second);
    }
    return ans;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<int> ans=topView(root);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}