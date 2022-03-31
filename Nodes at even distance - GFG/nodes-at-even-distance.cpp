// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
int dist[10001];
class Solution{
    //simple dfs ->we're traversing all the adjacent node 
    void dfs(int node,int p,vector<int>graph[]){
        for(auto &it : graph[node]){
            if(it==p) continue;
            dist[it]=dist[node]+1;
            dfs(it,node,graph);
        }
    }
    public:
    int countOfNodes(vector<int> graph[], int n)
    {
        // code here
        if(n==1) return 0;//only one node
        dfs(1,-1,graph);
        int even=0,odd=0;
        for(int i=1;i<=n;i++){
            if(dist[i]%2) odd++;
            else even++;
        }
        return (even*(even-1))/2+(odd*(odd-1))/2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends