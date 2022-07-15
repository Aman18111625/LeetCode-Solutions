// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Node{
  public:
  Node* child[2];
  int val;
  Node(){
      for(int i=0;i<2;i++) child[i]=NULL;
      val=0;
  }
};

class Trie{
  public:
  Node* root;
  Trie(){
      root=new Node();
  }
  
  void insert(int n){
      Node* temp=root;
      for(int i=31;i>=0;i--){
          int bit=(n>>i)&1;
          if(temp->child[bit]==NULL){
              temp->child[bit]=new Node();
          }
          temp=temp->child[bit];
      }
      temp->val=n;
  }
  
  int findXor(int n){
      Node* temp=root;
      for(int i=31;i>=0;i--){
          int bit=(n>>i)&1;
          if(temp->child[1-bit]!=NULL){
              temp=temp->child[1-bit];
          }else if(temp->child[bit]!=NULL){
              temp=temp->child[bit];
          }
      }
      return (temp->val)^n;
  }
  
};

class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){    
        //code here
        vector<int>PreXor(N);
        PreXor[0]=arr[0];
        for(int i=1;i<N;i++) PreXor[i]=PreXor[i-1]^arr[i];
        Trie *trie=new Trie();
        trie->insert(0);
        int ans=0;
        for(int i=0;i<N;i++){
            trie->insert(PreXor[i]);
            ans=max(ans,trie->findXor(PreXor[i]));
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends