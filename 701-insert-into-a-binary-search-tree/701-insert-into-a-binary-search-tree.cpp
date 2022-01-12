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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     if(!root)
     {
       TreeNode* node=new TreeNode(val);
         return node;
     }
        TreeNode* j=root;
        while(1)
        {
            if(val==j->val) return root;
            if(val<j->val) //left part
            {
                if(!j->left)
                {
                    TreeNode* t=new TreeNode(val);
                    j->left=t;
                    break;
                }
                else j=j->left;
            }
            else //right part
            {
                if(!j->right)
                {
                 TreeNode* t=new TreeNode(val);
                    j->right=t;
                    break;
                }
                else j=j->right;
            }
        }
        return root;
    }
};