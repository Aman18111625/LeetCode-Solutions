class Solution {
public:
    vector<vector<int>>graph,ans;
    vector<int>id,lowlink,vis;
    int time=0;
  
     void dfs(int node,int parent){
      id[node]=lowlink[node]=time++;
      vis[node]=true;
      for(int &x : graph[node]){
        if(parent==x) continue;
        if(!vis[x]){
          dfs(x,node);
          lowlink[node]=min(lowlink[node],lowlink[x]);
          if(id[node]<lowlink[x]){
            ans.push_back({node,x});
          }
        }else{
          lowlink[node]=min(lowlink[node],id[x]);
        }
      }
     }
  
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        vis.resize(n,false);
        lowlink.resize(n,0);
        id.resize(n,0);
        for(auto &x : connections){
          graph[x[0]].push_back(x[1]);
          graph[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false)
                dfs(i,i);
        }
        return ans;
    }
};

 
      