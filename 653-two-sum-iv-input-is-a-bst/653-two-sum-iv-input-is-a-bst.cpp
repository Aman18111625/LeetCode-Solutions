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
    unordered_set<int>s;
    bool helper(TreeNode* root,int k){
        if(!root) return false;
        if(s.count(k-root->val)) return true;
        else s.insert(root->val);
        bool left=helper(root->left,k);
        bool right=helper(root->right,k);
        return left || right;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return helper(root,k);
    }
};