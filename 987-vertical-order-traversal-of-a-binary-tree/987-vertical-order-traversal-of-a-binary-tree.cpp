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
  
 map<int, map<int, multiset<int>>> m;
    
    void helper(TreeNode* node, int i, int j)
    {
        if(node==NULL)return;
        
        m[j][i].insert(node->val);
        helper(node->left, i+1, j-1);
        helper(node->right, i+1, j+1);
    }
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 0, 0);
        vector<vector<int>> res;
        for(auto i:m)
        {
            vector<int> curr;
            for(auto ele:i.second)
            {
                for(auto s1:ele.second)
                    curr.push_back(s1);
            }
            res.push_back(curr);
        }
        return res;
    }
};