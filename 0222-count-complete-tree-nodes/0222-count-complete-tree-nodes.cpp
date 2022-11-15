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
   bool isLeaf(TreeNode* root){
     if(!root) return true;
     return !root->left && !root->right;
   }
public:
    int countNodes(TreeNode* root) {
      if(!root) return 0;
      if(isLeaf(root)) return 1;
      int cnt1=root->left==NULL?0:2+countNodes(root->left->left)+countNodes(root->left->right);
      int cnt2=root->right==NULL?0:1+countNodes(root->right->left)+countNodes(root->right->right);
      return cnt1+cnt2;
    }
};