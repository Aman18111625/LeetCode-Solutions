// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        // Code here
    //Using Priority-Queue
    //   vector<int>distance(v,INT_MAX);    
    //   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //   pq.push({0,src});
    //   distance[src]=0;
    //   while(!pq.empty()){
    //      int dist=pq.top().first;
    //      int prev=pq.top().second;
    //      pq.pop();
    //      for(auto it:adj[prev]){
    //           int next_dist=it[1];
    //           int next_node=it[0];
    //           if(dist+next_dist<distance[next_node]){
    //               distance[next_node]=dist+next_dist;
    //               pq.push({distance[next_node],next_node});
    //           }
    //       }
    //   }
    //   return distance;
    
    //Using Set
      vector<int>distance(v,INT_MAX);    
      set<pair<int,int>>st;//set stores everything in the asc order
      st.insert({0,src});
      distance[src]=0;
      while(!st.empty()){
         auto top =*(st.begin());
         int dist=top.first;
         int prev=top.second;
         st.erase(top);
         for(auto it:adj[prev]){
              int next_dist=it[1];
              int next_node=it[0];
              if(dist+next_dist<distance[next_node]){
                  if(distance[next_node]!=INT_MAX){
                      st.erase({distance[next_node],next_node});
                  }
                  distance[next_node]=dist+next_dist;
                  st.insert({distance[next_node],next_node});
              }
          }
      }
      return distance;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends