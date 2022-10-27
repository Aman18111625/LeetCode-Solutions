// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	 struct Node{
	     char dat;
	     int freq;
	    
	     Node *left,*right;
	   };
	  Node * newNode(char j,int f){
	      Node *n=new Node();
	      n->dat=j;
	      n->freq=f;
	      n->left=NULL;
	      n->right=NULL;
	  }
	    struct cmpare{
	      bool operator()(Node *l,Node *r){
	          return l->freq>r->freq;
	      }  
	    };
	   
	    void preorder(Node *r,string t,vector<string>&a ){
	        if(r->left==NULL and r->right==NULL)
	        {
	            a.push_back(t);
	            return;
	        }
	        preorder(r->left,t+'0',a);
	        preorder(r->right,t+'1',a);
	        
	    }
	    
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    Node *root=NULL;
		    priority_queue<Node *,vector<Node *>,cmpare>p;
		    for(int i=0;i<N;i++){
		        Node *t=newNode(S[i],f[i]);
		        p.push(t);
		    }
		    vector<string>v;
		    while(p.size()>1){
		        Node *n;
		        Node *l=p.top();
		        p.pop();
		        Node *r=p.top();
		        p.pop();
		        n=newNode('*',l->freq+r->freq);
		        if(l->freq<=r->freq){
		            n->left=l;
		            n->right=r;
		        }
		        else{
		            n->left=r;
		            n->right=l;
		        }
		        p.push(n);
		    }
		    root=p.top();
		    string s;
		    preorder(root,s,v);
		    return v;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends