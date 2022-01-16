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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int size=q.size(),curMin=q.front().second,leftMost,rightMost;
            for(int i=0;i<size;i++)
            {
                 int curr=q.front().second-curMin;
                 TreeNode* temp=q.front().first; q.pop();
                 if(i==0) leftMost=curr;
                 if(i==size-1) rightMost=curr;
                 if(temp->left) q.push({temp->left,curr*2+1});
                 if(temp->right) q.push({temp->right,curr*2+2});
            }
            ans=max(ans,rightMost-leftMost+1);
        }
        return ans;
    }
};