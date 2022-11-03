//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>adj[n];
        for(auto it: flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});//stops ,{node,cost}
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int stops=temp.first;
            int node=temp.second.first;
            int cost=temp.second.second;
            
            if(stops>K) break;
            for(auto &it : adj[node]){
                int v=it.first;
                int wt=it.second;
                if(cost+wt<dist[v]){
                    dist[v]=cost+wt;
                }
                q.push({stops+1,{v,cost+wt}});
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends