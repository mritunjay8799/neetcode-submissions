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
// Way 1 - Find Inorder and return item k-1 index;
// Way 2 - Traverse Inorder but till k items are covered, then return. 
    
    void helper(TreeNode* root, int k, int& count, int& result){
        if(!root) return;
        helper(root->left, k, count, result);
        count++;
        if(count == k){
            result = root->val;
            return;
        }
        helper(root->right, k, count, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0, result = 0;
        helper(root, k, count, result);
        return result;
    }
};
