/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(!root) return "";
       queue<TreeNode*>q;
       string ans="";
       q.push(root);
      while(!q.empty())
      {
        auto temp=q.front(); q.pop();
        if(!temp) ans.append("#,");
        else ans.append(to_string(temp->val)+',');
        if(temp)
        {
          q.push(temp->left);
          q.push(temp->right);
        }
      }
      return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
         stringstream ss(data);
         string str;
         getline(ss,str,',');
         TreeNode* root= new TreeNode(stoi(str));
         queue<TreeNode*>q;
         q.push(root);
      while(!q.empty()){
        auto temp=q.front(); q.pop();
        getline(ss,str,',');
        if(str=="#") temp->left=NULL;
        else{
          TreeNode* left=new TreeNode(stoi(str));
          temp->left=left;
          q.push(left);
        }
        getline(ss,str,',');
        if(str=="#") temp->right=NULL;
        else{
          TreeNode* right=new TreeNode(stoi(str));
          temp->right=right;
          q.push(right);
        }
      }
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;