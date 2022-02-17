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
     int helper(TreeNode* root,unordered_map<int,int>&mpp,int &max_freq){
     if(!root) return 0;
     int sum=root->val;
     sum+=helper(root->left,mpp,max_freq);
     sum+=helper(root->right,mpp,max_freq);
     mpp[sum]++;
     max_freq=max(max_freq,mpp[sum]);
     return sum;
  }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
         vector<int>ans;
         if(!root) return ans;
         unordered_map<int,int>mpp;
         int max_freq=0;
         helper(root,mpp,max_freq);
         for(auto &it : mpp)
         {
           if(it.second==max_freq) ans.push_back(it.first);
         }
      return ans;
    }
};