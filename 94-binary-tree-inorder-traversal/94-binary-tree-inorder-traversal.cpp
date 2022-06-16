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
   //Recursive
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
     
  //Iterative
  //TC:=>O(N)
  //SC:=>O(N)
      // vector<int> inorderTraversal(TreeNode* root) {
      //   vector<int>ans;
      //   if(!root) return ans;
      //   stack<TreeNode*>st;
      //   while(1){
      //     if(root){
      //       st.push(root);
      //       root=root->left;
      //     }else{
      //       if(st.empty()) break;
      //       root=st.top(); st.pop();
      //       ans.push_back(root->val);
      //       root=root->right;
      //     }
      //   }
      //   return ans;
      // }
  //Using Morris Traversal
  //TC:=>O(N)
  //SC:=>O(1)
  vector<int> inorderTraversal(TreeNode* root){
     vector<int>ans;
     if(!root) return ans;
     TreeNode* curr=root;
     while(curr){
       if(!curr->left){
        ans.push_back(curr->val);
        curr=curr->right;
       }else{
         TreeNode* prev=curr->left;
         while(prev->right && prev->right!=curr){
           prev=prev->right;
         }
         if(!prev->right){
           prev->right=curr;
           curr=curr->left;
         }else{
           prev->right=NULL;
           ans.push_back(curr->val);
           curr=curr->right;
         }
       }
     }
     return ans;
  }
};
 