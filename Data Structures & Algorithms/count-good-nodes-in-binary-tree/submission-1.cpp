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
    void helper(TreeNode* root, int& count, int maxSoFar) {
        if (!root) return;
        if (root->val >= maxSoFar)
            count++;
        int newMax = max(maxSoFar, root->val);
        helper(root->left, count, newMax);
        helper(root->right, count, newMax);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int count = 0;
        helper(root, count, root->val);
        return count;
    }
};
