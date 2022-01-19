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


class Tuple{
    public:
    int mini,maxi,sum,isBST;
    Tuple(int mini,int maxi,int sum,int isBST)
    {
        this->mini=mini;
        this->maxi=maxi;
        this->sum=sum;
        this->isBST=isBST;
    }
};

class Solution {
    int ans;
    Tuple helper(TreeNode* root)
    {  
         if(!root) return Tuple(INT_MAX,INT_MIN,0,true);
         Tuple lft=helper(root->left);
         Tuple rgt=helper(root->right);
         if((lft.isBST && rgt.isBST) && (lft.maxi<root->val) && (root->val < rgt.mini) )
         {
                ans=max(ans,root->val+lft.sum+rgt.sum);
                int newmax=max({root->val,lft.maxi,rgt.maxi});
                int newmin=min({root->val,lft.mini,rgt.mini});
                int newsum=root->val +lft.sum+rgt.sum;
          
                return Tuple(newmin,newmax,newsum,true);
         }
         return Tuple(INT_MAX,INT_MIN,0,false);  
    }
    public:
    int maxSumBST(TreeNode* root) {
        if(!root) return 0;
        ans=0;
        helper(root);
        return ans;
    }
};
