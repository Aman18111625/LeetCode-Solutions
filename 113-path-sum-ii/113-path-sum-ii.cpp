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
void helper(TreeNode* root,int target,int curr,vector<int>&temp,vector<vector<int>>&ans){
      if(!root) return ;
      curr+=root->val;
      temp.push_back(root->val);
      if(curr==target && root->left==root->right){
        ans.push_back(temp);
      }
      helper(root->left,target,curr,temp,ans);
      helper(root->right,target,curr,temp,ans);
      temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<vector<int>>ans;
      vector<int>temp;
      helper(root,targetSum,0,temp,ans);
      return ans;
    }
};