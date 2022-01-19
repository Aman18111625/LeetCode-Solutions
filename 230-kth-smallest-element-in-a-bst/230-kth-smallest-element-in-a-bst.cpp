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
      vector<int>in;
    void inorder(TreeNode* root,int k)
    {
        if(!root) return ;
        inorder(root->left,k);
        in.push_back(root->val);
        inorder(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        in.clear();
        inorder(root,k);
        return in[k-1];
    }*/
     void helper(TreeNode* root, int& k, int& val){
        if(!root || val) return;
        helper(root->left, k, val);
        if(--k == 0){
            val= root->val;
            return;
        }              
        helper(root->right, k, val);
    }
    public:
    
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;  
        helper(root, k, val);
        return val;
    }
};