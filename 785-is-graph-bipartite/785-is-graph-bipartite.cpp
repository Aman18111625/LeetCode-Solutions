class Solution {
public:
//BFS Appraoch
//   bool checkBipartite(vector<vector<int>>&graph,int node,vector<int>&color){
//     queue<int>q;
//     q.push(node);
//     color[node]=1;
//     while(!q.empty()){
//       auto temp=q.front();q.pop();
//       for(auto &it: graph[temp]){
//        if(color[it]==-1){
//         color[it]=1-color[temp];
//         q.push(it);
//        }else if(color[it]==color[temp]) return false;
//       }
//     }
//     return true;
//   }

//     bool isBipartite(vector<vector<int>>& graph) {
//          int n=graph.size();
//          vector<int>color(n,-1);
//          for(int i=0;i<n;i++){
//            if(color[i]==-1)
//              if(!checkBipartite(graph,i,color)) return false;
//          }
//       return true;
//     }
  
  bool dfs(vector<vector<int>>&graph,vector<int>&color,int node){
      for(auto it : graph[node]){
        if(color[it]==-1){
           color[it]=1-color[node];
           if(dfs(graph,color,it)==false) return false;
        }else if(color[it]==color[node]) return false;
      }
      return true;
  }
  
  bool isBipartite(vector<vector<int>>& graph){
      int n=graph.size();
      vector<int>color(n,-1);
      for(int i=0;i<n;i++){
        if(color[i]==-1){
          if(!dfs(graph,color,i)) return false;
        }
      }
     return true;
  }
};