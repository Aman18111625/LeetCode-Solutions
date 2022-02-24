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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
          int size=q.size();
          int maxi=q.front()->val;
          for(int i=0;i<size;i++){
              auto temp=q.front(); q.pop();
              maxi=max(maxi,temp->val);
              if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
          }
          ans.push_back(maxi);
        }
      return ans;
    }
};