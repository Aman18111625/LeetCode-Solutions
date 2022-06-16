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
   void helper(TreeNode* root,vector<int>&post){
     if(!root) return ;
     helper(root->left,post);
     helper(root->right,post);
     post.push_back(root->val);
   }
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>post;
       helper(root,post);
       return post;
    }
};