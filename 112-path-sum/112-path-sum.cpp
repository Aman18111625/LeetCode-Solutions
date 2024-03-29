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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left and !root->right and root->val!=targetSum) return false;
        if(!root->left and !root->right and root->val==targetSum ) return true;;
        bool f1=hasPathSum(root->left,targetSum-root->val);
        bool f2=hasPathSum(root->right,targetSum-root->val);
        if(f1 or f2) return true;
        return false;
    }
};