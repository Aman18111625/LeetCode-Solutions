class Solution {
  bool checkBipartite(vector<vector<int>>&graph,int node,vector<int>&color)
  {
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty())
    {
      auto temp=q.front();q.pop();
     for(auto &it: graph[temp])
     {
       if(color[it]==-1)
       {
        color[it]=1-color[temp];
        q.push(it);
       }else if(color[it]==color[temp]) return false;
      }
    }
    return true;
  }
public:
    bool isBipartite(vector<vector<int>>& graph) {
         int n=graph.size();
         vector<int>color(n,-1);
         for(int i=0;i<n;i++)
         {
           if(color[i]==-1)
           {
             if(!checkBipartite(graph,i,color)) return false;
           }
         }
      return true;
    }
};