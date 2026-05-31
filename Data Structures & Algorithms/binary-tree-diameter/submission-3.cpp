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
    int findHeight(TreeNode* root){
        if(!root)
            return 0;

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        int diameter = leftHeight + rightHeight;

        int subTreeDiameter = max(diameterOfBinaryTree(root->left), 
                                  diameterOfBinaryTree(root->right));

        return max(diameter, subTreeDiameter);
    }
};
