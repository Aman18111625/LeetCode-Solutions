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
   int  helper(TreeNode* root, int curr) {
        if(!root) return 0;
        curr = (curr<<1)|(root->val);
        if(!root->left && !root->right) return curr;
        return helper(root->left, curr) + helper(root->right, curr);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return helper(root,0);
    }
    */
    public:
     int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        stack<pair<TreeNode*,int>> st;
        st.push({root,0});
        while(!st.empty()) {
            auto node= st.top(); st.pop();
            TreeNode* cur = node.first;
            int cur_val = node.second;
            // Equivalent to left shift by 1 and then ORing by cur->val.
            cur_val = cur_val*2 + cur->val;
            
            if(!cur->left && !cur->right)
                ans += cur_val;
            
            if(cur->left) st.push({cur->left, cur_val});
            if(cur->right) st.push({cur->right, cur_val});
        }
        
        return ans;
        
    }
};