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
  /*
    int findBottomLeftValue(TreeNode* root) {
       if(!root) return 0;
       if(!root->left && !root->right) return root->val;
       queue<TreeNode*>q;
       vector<int>ans;
       q.push(root);
       while(!q.empty()){
          int size=q.size();
          ans.clear();
          for(int i=0;i<size;i++){
            auto node=q.front(); q.pop();
            ans.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
          }
      }
      return ans[0];
    }*/
  //we're applying reverse bfs because in simple bfs we'll get right most node at the top of queue 
  int findBottomLeftValue(TreeNode* root) {
    if(!root) return 0;
    queue<TreeNode* >q;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();
        q.pop();
        if(root->right)
            q.push(root->right);
        if(root->left)
            q.push(root->left);
        
    }
    return root->val;
}
};