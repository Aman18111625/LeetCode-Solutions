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
    TreeNode* helper(vector<int>&pre,int n,int key,int *preStart,int mini,int maxi)
    {
        if(*preStart>=n) return NULL;
        TreeNode* root= NULL;
        if(key>mini && key<maxi)
        {
            root=new TreeNode(key);
            *preStart=*preStart+1;
            if(*preStart<n)
            {
                root->left=helper(pre,n,pre[*preStart],preStart,mini,key);
            }
            if(*preStart<n)
            {
                root->right=helper(pre,n,pre[*preStart],preStart,key,maxi);
            }
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preStart=0;
        int n=preorder.size();
        return helper(preorder,n,preorder[0],&preStart,INT_MIN,INT_MAX);
    }
};