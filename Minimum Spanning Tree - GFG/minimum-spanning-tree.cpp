//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
        // code here
     //prim's algorithm
    //   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //   vector<int>vis(V,false);
    //   pq.push({0,0});//wt,node
    //   int sum=0;
    //   while(!pq.empty()){
    //       auto it=pq.top();
    //       pq.pop();
    //       int wt=it.first;
    //       int node=it.second;
    //       if(vis[node]) continue;
    //       vis[node]=true;
    //       sum+=wt;
    //       for(auto it: adj[node]){
    //           int adjNode=it[0];
    //           int weight=it[1];
    //           if(!vis[adjNode]){
    //               pq.push({weight,adjNode});
    //           }
    //       }
    //   }
    //   return sum;
    // }
    void Union(int u, int v, vector<int>&parent, vector<int>&rank){
        int rank1=parent[u];
        int rank2=parent[v];
        if(rank1==rank2) return;
        
        if(rank[rank1]<rank[rank2])
            parent[rank1]=rank2;
        else if(rank[rank1]>rank[rank2])
            parent[rank2]=rank1;
        else{
            parent[rank1]=rank2;
            rank[rank2]++;
        }
    }


    int findParents(int x , vector<int> & parent){
      if(x==parent[x])
          return x;
      else
          return findParents(parent[x],parent);
    }

      static bool comp(vector<int> & a, vector<int>& b){
        return a[2]<b[2];
      }

  int spanningTree(int V, vector<vector<int>> adj[]){
        vector<vector<int> > v;
        for(int i=0;i<V;i++){
          for(auto it: adj[i])
            v.push_back({i,it[0],it[1]});
         }
         sort(v.begin(),v.end(),comp);
         vector<int> parent(V),rank(V,0);
         for(int i=0;i<V;i++)
            parent[i]=i;
                
        int cost=0;
        for(int i=0;i<v.size();i++){
            int r11=findParents(v[i][0],parent);
            int r22=findParents(v[i][1],parent);
            if(r11!=r22){
              cost+=v[i][2];
              Union(r11,r22,parent,rank);
            }
        }
        return cost;
   }
};

//{ Driver Code Starts.


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