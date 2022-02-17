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
     unordered_map<int,int>mpp;
     int helper(TreeNode* root){
     if(!root) return 0;
     int sum=root->val;
     sum+=helper(root->left);
     sum+=helper(root->right);
     mpp[sum]++;
     return sum;
  }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
         vector<int>ans;
         if(!root) return ans;
         helper(root);
         int max_freq=0;
         for(auto &it : mpp) max_freq=max(max_freq,it.second);
         for(auto &it : mpp)
         {
           if(it.second==max_freq) ans.push_back(it.first);
         }
      return ans;
    }
};