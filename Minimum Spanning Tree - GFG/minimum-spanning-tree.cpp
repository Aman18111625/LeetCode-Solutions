// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//Brute-Force
	//TC:->O(N^2)
	//SC:O(N)
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
    //     // code here
    //     int parent[V];
    //     int key[V]; 
    //     bool mstSet[V]; 
  
    //     for (int i = 0; i < V; i++) 
    //         key[i] = INT_MAX, mstSet[i] = false; 
        
    //     key[0] = 0; 
    //     parent[0] = -1; 
    //     int ansWeight = 0;
    //     for (int count = 0; count < V - 1; count++){ 
    //         int mini = INT_MAX, u; 
    //         for (int v = 0; v < V; v++) {
    //         if (mstSet[v] == false && key[v] < mini) 
    //             mini = key[v], u = v; 
    //         }
            
    //         mstSet[u] = true; 
    //         for (auto it : adj[u]) {
    //          int v = it[0];
    //          int weight = it[1];
    //          if (mstSet[v] == false && weight < key[v]) 
    //             parent[v] = u, key[v] = weight; 
    //         }
    //     } 
    //      int sum=0;
    //      for(int i=1;i<V;i++)
    //             sum+=key[i];
                
    //     return sum;
    // }
    int spanningTree(int V, vector<vector<int>> adj[]){
        int sum=0;
        int parent[V];
        int key[V];
        bool MST[V];
        
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<V;i++){
            key[i]=INT_MAX;
            parent[i]=-1;
            MST[i]=false;
        }
        key[0]=0;
        pq.push({0,0}); // {node,index}
        
        while(!pq.empty()){
            int u=pq.top().second; // index of minimal element
            pq.pop();
            
            MST[u]=true;  // now this node is part of MST
            
            for(auto it:adj[u]){ // traverse its neighbous
                int v=it[0];
                int weight=it[1];
                
                if(MST[v]==false && weight<key[v]){
                    parent[v]=u;
                    key[v]=weight;
                    pq.push({key[v],v});     
                }
            }
        }
        for(int i=1;i<V;i++)
          sum+=key[i];
          
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