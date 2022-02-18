class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
       int n=p.size();
       vector<pair<int,int>>adj[n];
       for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
           int dist=abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
           adj[i].push_back({j,dist});
           adj[j].push_back({i,dist});
         }
       }
        
        vector<int> dis(n, INT_MAX);//to keep track of mininum dist
        vector<bool> vis(n, false);//to keep track of visited or not
        dis[0] = 0;//starting node is 0 so distance from node 0 to node 0 is 0
        for(int count =1;count<n;count++){
            int mini = INT_MAX, u;
            for(int i=0;i<n;i++){
                if(mini>dis[i] and !vis[i]){
                    u=i, mini = dis[i];
                }
            }
            vis[u] = true;//mark true with minimum distance node
            for(auto it:adj[u]){//traverse for all the adjacent nodes of that node
                int node = it.first;
                int weight = it.second;
                if(!vis[node] and dis[node] > weight){
                 dis[node] = weight;
                }
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += dis[i];
        }
        return sum;
    }
};