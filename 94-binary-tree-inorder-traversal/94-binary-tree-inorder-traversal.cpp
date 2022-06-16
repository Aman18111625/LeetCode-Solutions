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
   //DFS 
   //TC:->O(N)(N->no of total nodes)
  //SC:->O(N) 
//     void helper(TreeNode* root,vector<int>&inorder){
//       if(!root) return ;
//       helper(root->left,inorder);
//       inorder.push_back(root->val);
//       helper(root->right,inorder);
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>inorder;
//         helper(root,inorder);
//         return inorder;
//     }
      vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        while(1){
          if(root){
            st.push(root);
            root=root->left;
          }else{
            if(st.empty()) break;
            root=st.top(); st.pop();
            ans.push_back(root->val);
            root=root->right;
          }
        }
        return ans;
      }
};

 