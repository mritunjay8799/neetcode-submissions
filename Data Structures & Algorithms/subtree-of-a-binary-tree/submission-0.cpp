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
    bool isSame(TreeNode* n1, TreeNode* n2){
        if(!n1 && !n2) return true;
        else if(!n1 || !n2) return false;

        return (n1->val == n2->val) && 
               isSame(n1->left, n2->left) && 
               isSame(n1->right, n2->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(isSame(root, subRoot)) return true;

        int left = isSubtree(root->left, subRoot);
        int right = isSubtree(root->right, subRoot);

        return left || right;
    }
};
