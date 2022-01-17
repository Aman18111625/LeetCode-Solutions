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
    TreeNode* helper(vector<int>&post,int sp,int ep,vector<int>&in,int si,int ei)
    {
        if(si>ei) return NULL;
        int idx=si;
        while(post[ep]!=in[idx]) idx++;
        int CountOfLeftNode=idx-si;
        TreeNode* root=new TreeNode(post[ep]);
        root->left=helper(post,sp,sp+CountOfLeftNode-1,in,si,idx-1);
        root->right=helper(post,sp+CountOfLeftNode,ep-1,in,idx+1,ei);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return helper(postorder,0,n-1,inorder,0,n-1);
    }
};