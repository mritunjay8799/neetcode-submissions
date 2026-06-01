/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void getInOrder(TreeNode* node, vector<int>&inorder){
        if(!node) return;
        getInOrder(node->left, inorder);
        inorder.push_back(node->val);
        getInOrder(node->right, inorder);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
    vector<int>inorder;
    if(!root) return 0;
    getInOrder(root, inorder);
    int n = inorder.size();
    if(k > n)
        return 0;
    return inorder[k-1];
    }
};
