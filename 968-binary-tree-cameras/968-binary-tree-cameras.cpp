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
  //In code we are using:
  // -1 to represent that node is not covered.
  // 0 to represent the node is having camera
  // 1 to represent the node is already covered.
   int helper(TreeNode* root,int &cameras){
     if(!root) return 1;
     int left=helper(root->left,cameras);
     int right=helper(root->right,cameras);
     if(left ==-1 || right==-1){
       cameras++;
       return 0;
     }
     if(left==0 or right==0) return 1;
     return -1;
   }
public:
    int minCameraCover(TreeNode* root) {
       if(!root) return 0;
       int cameras=0;
       if(helper(root,cameras)==-1) cameras++;
       return cameras;
    }
};