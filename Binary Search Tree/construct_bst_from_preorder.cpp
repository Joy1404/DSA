#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};
// optimal approach 
// time complexity: O(N)
// space complexity: O(H)
// approach: we use the fact that preorder traversal gives the root first, 
// then the left subtree, then the right subtree.
// we use the bound to check if the current element is within the range of the current subtree.
//  base case is when we reach the end of the array or the current element is greater than the bound.
//  we use the idx to keep track of the current element in the preorder traversal.
// in the function we create the root first, then we recursively call for the left subtree
// with the bound as root->data, then we recursively call for the right subtree with the bound as bound.
TreeNode*  build (vector<int>& preorder, int& idx, int bound){
    if(idx==preorder.size() || preorder[idx]>bound)return NULL;
    TreeNode* root=new TreeNode(preorder[idx++]);
    root->left=build(preorder,idx,root->data);
    root->right=build(preorder,idx,bound);
    return root;
}
TreeNode* constructBstOptimal(vector<int>& preorder){
    int idx=0;
    return build(preorder,idx,INT_MAX);
}

// Step 2: Build tree using preorder + inorder
TreeNode* buildTree(vector<int>& preorder, int preStart,
                    int inStart, int inEnd,
                    unordered_map<int, int>& inMap) {

    if (preStart >= preorder.size() || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int inRoot   = inMap[rootVal];       // root's position in inorder
    int numsLeft = inRoot - inStart;     // number of nodes in left subtree

    root->left  = buildTree(preorder, preStart + 1,
                            inStart, inRoot - 1, inMap);

    root->right = buildTree(preorder, preStart + numsLeft + 1,
                            inRoot + 1, inEnd, inMap);
    return root;
}

TreeNode* constructBstFromPreorder(vector<int>& preorder) {
    // Step 1: Sort preorder to get inorder
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());

    // O(1) lookup: value → index in inorder
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    return buildTree(preorder, 0, 0, inorder.size() - 1, inMap);
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


int main() {
    vector<int> preorder = {4, 2, 1, 3, 6, 5, 7};
    TreeNode* root = constructBstOptimal(preorder);
    inorderTraversal(root);
    return 0;
}