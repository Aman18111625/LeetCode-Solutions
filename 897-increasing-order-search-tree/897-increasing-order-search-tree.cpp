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
   void inorder(TreeNode* &ans,TreeNode* root)
    {
        if(!root) return ;
        inorder(ans,root->left);
        ans->right=new TreeNode(root->val);
        ans=ans->right;
        inorder(ans,root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        TreeNode* temp=new TreeNode();
        TreeNode* ans=temp;
        inorder(ans,root);
        return temp->right;
    }
};