class Solution {
public:
    void dfs(int node,vector<vector<int>>&graph,vector<int>&vis){
        vis[node]=1;
        for(auto it : graph[node]){
            if(!vis[it])
                dfs(it,graph,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
      int m=connections.size();
      if(n>m+1) return -1;//not enought cable
      vector<vector<int>>graph(n);
      for(auto it : connections){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
      }
      int cnt=0;
      vector<int>vis(n,0);
      for(int i=0;i<n;i++){
        if(!vis[i]){
          cnt++;
          dfs(i,graph,vis);
        }
      }
      return cnt-1;
    }
};