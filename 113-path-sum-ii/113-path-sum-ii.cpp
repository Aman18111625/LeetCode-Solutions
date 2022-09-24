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
//DFS Approach
// void helper(TreeNode* root,int target,int curr,vector<int>&temp,vector<vector<int>>&ans){
//       if(!root) return ;
//       curr+=root->val;
//       temp.push_back(root->val);
//       if(curr==target && root->left==root->right){
//         ans.push_back(temp);
//       }
//       helper(root->left,target,curr,temp,ans);
//       helper(root->right,target,curr,temp,ans);
//       temp.pop_back();
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//       vector<vector<int>>ans;
//       vector<int>temp;
//       helper(root,targetSum,0,temp,ans);
//       return ans;
//     }
    
  //BFS Approach
  //To check a node is leaf node or not
    bool isLeaf(TreeNode *root){
      return (!root->left and !root->right);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(!root) return ans;
        //<currRoot,<stillSum,currPathSum Vector>>
        queue<pair<TreeNode*,pair<int,vector<int>>>>q;
        q.push({root,{root->val,{root->val}}});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            auto currSum = curr.second.first;
            TreeNode *currRoot = curr.first;
            auto currPath = curr.second.second;
            if(isLeaf(currRoot) and currSum==targetSum){
                ans.push_back(currPath);
            }
            
            if(currRoot->left){
                auto leftPath = currPath;
                leftPath.push_back(currRoot->left->val);
                q.push({currRoot->left,{currSum + currRoot->left->val,leftPath}});
            }
            if(currRoot->right){
                auto rightPath = currPath;
                rightPath.push_back(currRoot->right->val);
                q.push({currRoot->right,{currSum + currRoot->right->val,rightPath}});
            }
        }
        return ans;
    }
};