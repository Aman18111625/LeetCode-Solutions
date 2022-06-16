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
  //Recursive Approach
  //TC:=>O(N)
  //SC:=>O(N)
//    void helper(TreeNode* root,vector<int>&post){
//      if(!root) return ;
//      helper(root->left,post);
//      helper(root->right,post);
//      post.push_back(root->val);
//    }

//     vector<int> postorderTraversal(TreeNode* root) {
//        vector<int>post;
//        helper(root,post);
//        return post;
//     }
    
  //Iterative Approach-1 :->Using Two Stacks
  //TC:=>O(N)
  //SC:=>O(N)
    vector<int> postorderTraversal(TreeNode* root){
      vector<int>ans;
      if(!root) return ans;
      stack<TreeNode*>st1,st2;
      st1.push(root);
      while(!st1.empty()){
        root=st1.top() ; st1.pop();
        st2.push(root);
        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
      }
      
      while(!st2.empty()){
        ans.push_back(st2.top()->val);
        st2.pop();
      } 
      return ans;
    }
};