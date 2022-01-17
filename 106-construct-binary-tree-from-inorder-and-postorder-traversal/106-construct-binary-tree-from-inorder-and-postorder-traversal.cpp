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
    //TC:=>O(N^2) SC:=>O(N)
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
    }*/
    
//TC:=>O(N) SC:=>O(N)
unordered_map<int,int>m;
TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int start,int end,int &postIndex)
{
        if(start>end) return NULL;
         int inorderIndex = m[postorder[postIndex]];

        TreeNode* root = new TreeNode(inorder[inorderIndex]);    
        
        (postIndex)--;
        root->right=solve(inorder,postorder,inorderIndex+1,end,postIndex);
        root->left=solve(inorder,postorder,start,inorderIndex-1,postIndex);
        return root;
}
    
public:    
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
        int n=inorder.size();
        for(int i=0;i<n;i++){
           m[inorder[i]] = i;      
        }
        int postIndex=n-1;
        return solve(inorder,postorder,0,n-1,postIndex);
}
};