// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	typedef pair<int,int> pii;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>key(V,INT_MAX),parent(V,-1),mst(V,false);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
         parent[0]=-1;
         key[0]=0;
         pq.push({0,0});
         while(!pq.empty())
         {
            int node =pq.top().second;
            mst[node] = 1;
            pq.pop();
            for(auto& it: adj[node]) {
                int x = it[0];
                int wt = it[1];
                if(mst[x]==0 and wt<key[x]) {
                    key[x] = wt;
                    parent[x] = node;
                   pq.push({wt, x});
                }
            }
             
         }
      int sum=0;
      for(auto it: key) sum+=it;
      return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends