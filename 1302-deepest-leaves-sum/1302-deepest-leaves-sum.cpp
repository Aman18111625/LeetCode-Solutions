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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        queue<TreeNode*>q;  
        q.push(root);
        int sum=0;
        while(!q.empty()){
          int size=q.size();
          vector<int>temp;
          for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
          }
          if(q.empty()){
            for(auto it : temp) sum+=it;
          }
        } 
         return sum;
    }
};