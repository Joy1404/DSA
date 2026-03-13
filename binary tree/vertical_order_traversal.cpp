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
// approach: we will use a map to store the nodes according to their x and y coordinates. We will use a queue to perform a level order traversal of the tree and store the nodes in the map according to their coordinates. Finally, we will iterate through the map and insert the node values into the answer vector according to their coordinates.
vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(node->data);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
        for(auto it:nodes){ // it is a pair of (x, map of (y, multiset of node values)) like (-1, {(1, {2})}), (0, {(0, {1}), (1, {4,5})}), (1, {(1, {3}), (2, {6,7})})
            vector<int> temp;
            for(auto jt:it.second){ // jt is a pair of (y, multiset of node values) like (0, {1}), (1, {2,3}), (2, {4,5,6,7})
                temp.insert(temp.end(),jt.second.begin(),jt.second.end()); // insert the node values in the multiset into the temp vector, maintaining the order of y and the values in the multiset
            }
            ans.push_back(temp); 
        }
        return ans;

    }
    int main(){
        TreeNode* root=new TreeNode(1);
        root->left=new TreeNode(2);
        root->right=new TreeNode(3);
        root->left->left=new TreeNode(4);
        root->left->right=new TreeNode(5);
        root->right->left=new TreeNode(6);
        root->right->right=new TreeNode(7);
        vector<vector<int>> ans=verticalOrder(root);
        for(auto it:ans){
            for(auto jt:it){
                cout<<jt<<" ";
            }
            cout<<endl;
        }
        return 0;
    }