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
   //Iterative Approach
   //TC:=>O(N) 
   //SC:=>O(N)
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int>ans;
    //     if(!root) return ans;
    //     stack<TreeNode*>st;
    //     st.push(root);
    //     while(!st.empty()){
    //       TreeNode* node=st.top(); 
    //       ans.push_back(node->val);
    //       st.pop();
    //       if(node->right) st.push(node->right);
    //       if(node->left) st.push(node->left);
    //     }
    //     return ans;
    // }
   //Recursive Approach
   //TC:=>O(N)
   //SC:=>O(N)
    void preOrder(TreeNode* root,vector<int>&pre){
      if(!root) return ;
      pre.push_back(root->val);
      preOrder(root->left,pre);
      preOrder(root->right,pre);
    } 
  
   vector<int> preorderTraversal(TreeNode* root){
      vector<int>pre;
      if(!root) return pre;
      preOrder(root,pre);
      return pre;
  }
};