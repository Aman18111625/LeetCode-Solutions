/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        vector<int>v;
        queue<Node *>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            if(!temp){
               ans.push_back(v);
                v.clear();
                if(q.empty()) return ans;
                else q.push(NULL);
            }
            else{
                v.push_back(temp->val);
                for(auto x: temp->children ) q.push(x);
            }
        }
        return ans;
    }
};