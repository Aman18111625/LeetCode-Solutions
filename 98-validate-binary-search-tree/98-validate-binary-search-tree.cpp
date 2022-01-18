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
    bool helper(TreeNode* root,TreeNode* mini,TreeNode* maxi)
    {
        if(!root) return true;
        if(mini && root->val<=mini->val) return false;
        if(maxi && root->val>=maxi->val) return false;
        return helper(root->left,mini,root) && helper(root->right,root ,maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return helper(root,NULL,NULL);
    }
};