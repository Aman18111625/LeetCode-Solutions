// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

 struct Node{
       Node* child[26];
       bool isEnd;
       Node(){
           for(int i=0;i<26;i++){
               child[i]=NULL;
           }
           isEnd=false;
       }
};

  void insert(Node* root,string &s){
        for(auto ch: s){
            if(root->child[ch-'a']==NULL) root->child[ch-'a']=new Node();
            root=root->child[ch-'a'];
        }
        root->isEnd=true;
  }

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    bool search(Node* root,string s){
        int n=s.size();
        Node* temp=root;
        for(int i=0;i<n;i++){
            if(temp->child[s[i]-'a']==NULL) return false;
            temp=temp->child[s[i]-'a'];
        }
        return (temp&&temp->isEnd);
    }
    
    bool solve(Node* root,string s){
        int n=s.size();
        if(n==0) return true;
        for(int i=1;i<=n;i++){
            if(search(root,s.substr(0,i)) && solve(root,s.substr(i,n-i)) ) return true;
        }
        return false;
    }
    
    
    int wordBreak(string A, vector<string> &B) {
        //code here
      Node* root=new Node();
      for(auto it : B) insert(root,it);
      return solve(root,A);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends