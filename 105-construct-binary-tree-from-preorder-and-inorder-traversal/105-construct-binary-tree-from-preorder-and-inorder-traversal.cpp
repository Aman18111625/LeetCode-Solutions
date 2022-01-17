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
    TreeNode* helper(vector<int>&pre,int sp,int ep,vector<int>&in,int si,int ei)
    {
        if(si>ei) return NULL;
        int idx=si;
        while(pre[sp]!=in[idx]) idx++;
        int countOfLeftNode=idx-si;
        TreeNode* root=new TreeNode(pre[sp]);
        root->left=helper(pre,sp+1,sp+countOfLeftNode,in,si,idx-1);
        root->right=helper(pre,sp+countOfLeftNode+1,ep,in,idx+1,ei);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return helper(preorder,0,n-1,inorder,0,n-1);
    }
};