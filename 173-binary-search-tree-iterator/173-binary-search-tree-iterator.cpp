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
class BSTIterator {
       vector<int>in;
        void inorder(TreeNode* root)
       {
           if(!root) return ;
           inorder(root->left);
           in.push_back(root->val);
           inorder(root->right);
       }
       int idx;
public:
    BSTIterator(TreeNode* root) {
        in.clear();
        idx=0;
        inorder(root);
    }
    
    int next() {
        return in[idx++];
    }
    
    bool hasNext() {
        return idx<in.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */