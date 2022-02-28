class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
      vector<pair<int,double>>adj[n];
      int size=edges.size();
     for(int i=0;i<size;i++){
        int x=edges[i][0];
        int y=edges[i][1];
        double succ=succProb[i];
        adj[x].push_back({y,succ});
        adj[y].push_back({x,succ});
    }
    vector<double>distance(n,0.0);
    priority_queue<pair<int,double>>pq;
    pq.push({start,1.0000});
    distance[start]=1.0000;
    while(!pq.empty()){
        int src=pq.top().first;
        double dist=pq.top().second;
        pq.pop();
        for(auto it : adj[src]){
            int next=it.first;
            double nextDist=it.second;
            if(distance[next]<dist*nextDist){
                distance[next]=dist*nextDist;
                pq.push({next,distance[next]});
            }
        }
    }
    return distance[end];//==INT_MIN?0:distance[end];
    }
};

        
      