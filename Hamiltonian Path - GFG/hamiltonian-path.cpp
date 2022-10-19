//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool dfs(int N, vector<int> adj[], vector<int>&vis, int node, int &count){
        vis[node]=1;
        count++;
        if(count==N){
            return true;
        }
        for(int i:adj[node]){
            if(!vis[i]){
                if(dfs(N, adj, vis, i, count))
                    return true;
            }
        }
        vis[node]=0; //BackTracking
        count--;
        return false;
    }
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
       vector<int> adj[N+1];
       for(int i=0;i<Edges.size();i++){
           adj[Edges[i][0]].push_back(Edges[i][1]);
           adj[Edges[i][1]].push_back(Edges[i][0]);
       }
       vector<int>vis(N+1,0);
       for(int i=1; i<=N; i++){
           int cnt=0;
           if(dfs(N, adj, vis, i, cnt)){
               return true;
           }
       }
       return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends