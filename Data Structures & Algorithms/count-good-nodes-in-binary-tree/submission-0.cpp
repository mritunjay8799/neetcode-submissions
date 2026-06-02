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
    void helper(TreeNode* root, int& count, int ref){
        if(!root) return;
        helper(root->left, count, max(ref,root->val));
        if(root->val >= ref)
            count++;
        helper(root->right, count, max(ref,root->val));
        return;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count  = 0,  ref = INT_MIN;
        helper(root, count, ref);
        return count;
    }
};
