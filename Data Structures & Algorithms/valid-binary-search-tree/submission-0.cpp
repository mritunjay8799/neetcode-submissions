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
//Way 1 - Inorder Traversal of BST gives sorted list if valid
//Way 2 - for each node find range of values it can hold
    bool isValid(TreeNode* node, int minVal, int maxVal){
        if(!node) return true;
        else if(node->val <= minVal || node->val >= maxVal) return false;

        return isValid(node->left, minVal, node->val) &&
                isValid(node->right, node->val, maxVal); 
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};
