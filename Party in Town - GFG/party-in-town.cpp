// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
     int BFS(vector<vector<int>>&adj,int ind,vector<int>&vis){
         queue<int>q;
         q.push(ind);
         vis[ind]=true;
         int cnt=0;
         while(!q.empty()){
             int n=q.size();
             while(n--){
                 int temp=q.front(); q.pop();
                 vis[temp]=true;
                 for(auto m : adj[temp]){
                     if(!vis[m]) q.push(m);
                 }
             }
             cnt++;
         }
         return cnt-1;
     }
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        // code here
        int ans=INT_MAX;
        for(int i=1;i<=N;i++){
            vector<int>vis(N+1,false);
            int curr=BFS(adj,i,vis);
            ans=min(ans,curr);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends