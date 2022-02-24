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
  int findMaxIndex(vector<int>&nums,int l,int r){
    int maxIdx=l;
    int maxi=nums[l];
    for(int i=l;i<=r;i++) 
    {
      if(nums[i]>maxi){
        maxi=nums[i];
        maxIdx=i;
      }
    }
    return maxIdx;
  }
  TreeNode* helper(vector<int>&nums,int l,int r){
    if(l>r) return NULL;
    int maxIdx=findMaxIndex(nums,l,r);
    TreeNode* root=new TreeNode(nums[maxIdx]);
    root->left=helper(nums,l,maxIdx-1);
    root->right=helper(nums,maxIdx+1,r);
    return root;
  }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
          if(nums.empty()) return NULL;
          int n=nums.size();
          return helper(nums,0,n-1);
    } 
};