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
  /*
    void helper(TreeNode* root,int& val,int& depth,int level){
      if(!root) return ;
      if(level==depth-1){
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        root->left=new TreeNode(val);
        root->right=new TreeNode(val);
        root->left->left=left;
        root->right->right=right;
        return ;
      }
      helper(root->left,val,depth,level+1);
      helper(root->right,val,depth,level+1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       if(depth==1){
         TreeNode* newNode=new TreeNode(val);
         newNode->left=root;
         return newNode;
       }
       helper(root,val,depth,1);
       return root;
    }*/
  TreeNode* addOneRow(TreeNode *root, int val, int depth, string direction){
    if(depth == 1){
        TreeNode *curr = new TreeNode(val);
        if(direction == "comingFromLeft") curr->left = root;
        if(direction == "comingFromRight") curr->right = root;
        return curr;
    }
    
    if(root == nullptr) return root;

    root->left = addOneRow(root->left,val,depth-1,"comingFromLeft");
    root->right = addOneRow(root->right,val,depth-1,"comingFromRight");
    return root;
}
public:
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    return addOneRow(root,val,depth,"comingFromLeft");
}
};