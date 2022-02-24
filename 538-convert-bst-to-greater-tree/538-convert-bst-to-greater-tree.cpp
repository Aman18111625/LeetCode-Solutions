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
    int sum;
    void helper(TreeNode* root){
     if(!root) return ;
     helper(root->right);
     root->val+=sum;
     sum=root->val;
     helper(root->left);
   }
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        sum=0;
        helper(root);
        return root;
    }
};