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
   int findMinFromRight(TreeNode* root){
        while(root->left) root=root->left;
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(!root) return root;
      else if(root->val>key) root->left=deleteNode(root->left,key);
      else if(root->val<key) root->right=deleteNode(root->right,key);
      else{
        if(!root->right) return root->left;
        else if(!root->left) return root->right;
        else{
          //replace the root with minimum from the right side
          root->val=findMinFromRight(root->right);
          root->right=deleteNode(root->right,root->val);
        }
      } 
      return root;
    }
};
 