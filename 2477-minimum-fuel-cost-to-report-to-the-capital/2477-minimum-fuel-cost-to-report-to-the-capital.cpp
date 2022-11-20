class Solution {
  long long ans=0;
  //return how many seats required for all the adjacent 
  long long dfs(int src,int &seats,vector<int>&vis,vector<vector<int>>&adj){
    vis[src]=1;//mark vis
    long long cnt=1;
    //run dfs for all the adjacent
    for(auto node: adj[src]){
      if(!vis[node]){
        cnt+=dfs(node,seats,vis,adj);
      }
    }
    if(cnt<=seats) ans++;
    else{
      long long extraCars = ceil(cnt/(seats*1.0));
      ans += extraCars;
    }
    return cnt;
  }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
      int n=roads.size();
      //create adjacency matrix
      vector<vector<int>>adj(n+1);
      for(auto &it : roads){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }
      
      vector<int>vis(n+1,false);
      //start with root node
      vis[0]=true;
      
      for(auto it: adj[0]){
        dfs(it,seats,vis,adj);
      }
      return ans;
    }
};

  
    
    