// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

struct Node{
  Node* child[2];
  Node(){
      for(int i=0;i<2;i++) child[i]=NULL;
  }
};

void insert(Node* root,int num){
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1LL;
        if(root->child[bit]==NULL) root->child[bit]=new Node();
        root=root->child[bit];
    }
}

int findMinXor(Node*root,int num){
    int ans=0;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1LL;
        if(root->child[bit]) root=root->child[bit];
        else {
            ans|=(1LL<<i);
            root=root->child[1^bit];
        }
    }
    return ans;
}

class Solution{   
public:
    int minxorpair(int N, int arr[]){    
        //code here
        Node* root=new Node();
        insert(root,arr[0]);
        int ans=INT_MAX;
        for(int i=1;i<N;i++){
            ans=min(ans,findMinXor(root,arr[i]));
            insert(root,arr[i]);
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
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends