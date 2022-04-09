// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
    Node* locate(Node* root, int target){
       if(root==NULL) return NULL;
       if(root -> data == target)
           return root;
       Node* lNode = locate(root -> left, target);
       Node* rNode = locate(root -> right, target);
       
       if(lNode) return lNode;
       if(rNode) return rNode;
       
       return NULL;
   }
   void markParent(Node* root, unordered_map<Node*, Node*>&umap){
       if(root==NULL) return;
       queue<Node*>q;
       umap.insert({root, NULL});
       q.push(root);
       while(!q.empty()){
           Node* tmp = q.front();
           q.pop();
           
           if(tmp){
               if(tmp -> left){
                   umap.insert({tmp -> left, tmp});
                   q.push(tmp -> left);
               }
               if(tmp -> right){
                   umap.insert({tmp -> right, tmp});
                   q.push(tmp -> right);
               }
           }
       }
    }
    int sum_at_distK(Node* root, int target, int k)
    {
      if(root==NULL)
           return 0;
       
       Node* tar = locate(root, target);
       unordered_map<Node*, Node*>umap;
       markParent(root, umap);
       
       int dist=0, sum=0;
       queue<Node*>q;
       q.push(tar);
       unordered_set<Node*>check;
       check.insert(tar);
       
       while(!q.empty()){
           if(dist++>k)
               break;
           int size = q.size();
           for(int i=0;i<size;i++){
               Node* tmp = q.front();
               q.pop();
               sum+=tmp -> data;
               
               if(tmp -> left && check.count(tmp -> left)==0){
                   q.push(tmp -> left);
                   check.insert(tmp -> left);
               }                
               
               if(tmp -> right && check.count(tmp -> right)==0){
                   q.push(tmp -> right);
                   check.insert(tmp -> right);
               }
               
               if(umap[tmp] && check.count(umap[tmp])==0){
                   q.push(umap[tmp]);
                   check.insert(umap[tmp]);
               }
               
           }
       }
       
       return sum;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends