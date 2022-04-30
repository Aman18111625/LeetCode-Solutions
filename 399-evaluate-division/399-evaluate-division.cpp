class Solution {
public:
void createAdjList(unordered_map<string,unordered_map<string,double>>& adj,vector<vector<string>>&equations,vector<double>&values){
         int i=0;
         for(auto &it : equations){
            string from=it[0];
            string to=it[1];
            adj[from].insert({to,values[i]});
            adj[to].insert({from,(double)1/values[i]});
            i++;
        }
    }
   
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& q) {
       int n=q.size();
       vector<double>ans(n);
       //we'll be using unordered_map to store the data
       unordered_map<string,unordered_map<string,double>>adj;
       createAdjList(adj,equations,values);
       //calculate res for each query
        for(int i=0;i<n;i++){
         unordered_set<string>vis;
         ans[i]=dfs(q[i][0],q[i][1],vis,adj);
       }
       return ans;
    }
    
    double dfs(string s,string d,unordered_set<string>&vis,unordered_map<string,unordered_map<string,double>>&adj){
      if(adj.find(s)==adj.end()) return -1.0;//if src is not found ->return -1.0
      if(adj[s].find(d)!=adj[s].end()) return adj[s][d];
      vis.insert(s);//mark as visited
      //explore all the paths
      for(auto &it : adj[s]){
        if(!vis.count(it.first)){
          double ans=dfs(it.first,d,vis,adj);
          if(ans!=-1.0) return (double)ans*(it.second);
        }
      }
      return -1.0;
    }
  
};

        