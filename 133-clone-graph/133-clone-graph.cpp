/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  /*
    void dfs(Node *curr,Node *node,vector<Node*>&vis)
    {
        vis[node->val]=node;
        for(auto &elem : curr->neighbors)
        {
          if(!vis[elem->val])
          {
              Node *newNode=new Node(elem->val);
              (node->neighbors).push_back(newNode);
              dfs(elem,newNode,vis);
          }
          else
          {
              (node->neighbors).push_back(vis[elem->val]);
          }
        }
    }
public:
    Node* cloneGraph(Node* node) {
       if(!node) return node;
       Node* copy= new Node(node->val);
       vector<Node*>vis(101,NULL);
       vis[copy->val]=copy;
       for(auto &child : node->neighbors){
         if(!vis[child->val]){
           Node* temp=new Node(child->val);
           (copy->neighbors).push_back(temp);
           dfs(child,temp,vis);
         }else{
            (copy->neighbors).push_back(vis[child->val]);
         }
       }
      return copy;
    }
  */
  public:
    unordered_map<Node*,Node*>vis={{NULL,NULL}};
    Node* cloneGraph(Node* node) {
        return clone(node);
    }
    
    Node* clone(Node* node) {
        if (vis.count(node))
            return vis[node];
        
        auto newNode = new Node(node->val);
        vis[node] = newNode;
        for (auto &child : node->neighbors)
            newNode->neighbors.push_back(clone(child));
        
        return newNode;
    }
};