class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<pair<int,int>>graph[n+1];
        for(auto it : t){
          graph[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        pair<int,int>temp;
        bool vis[n+1];
        memset(vis,0,sizeof(vis));
        while(!pq.empty()){
          temp=pq.top(); pq.pop();
          int u=temp.second;
          vis[u]=true;
          for(auto it : graph[u]){
            int v=it.first;
            int weight=it.second;
            if(!vis[v] && dist[v]>dist[u]+weight){
              dist[v]=dist[u]+weight;
              pq.push({dist[v],v});
            }
          }
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
          ans=max(ans,dist[i]);
        }
      if(ans==1e9) return -1;
      return ans;
    }
};

   
    