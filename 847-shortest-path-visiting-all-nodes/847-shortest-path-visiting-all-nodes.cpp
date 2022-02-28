class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1) return 0;//if only 1 node then shortest path is zero
        string allvisit(n,'1');//to keep track of all nodes 
        queue<pair<int,string>> q;
        string cur(n,'0');
        set<pair<int,string>> vis;
      //we'll each and every node into the queue and mark as visited because ATQ start node->variable
        for(int i=0;i<n;i++){
            cur[i]='1';
            q.push({i,cur}); 
            vis.insert({i,cur});
            cur[i]='0';
        }
        int step=0,v; char tempchr;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                 v=q.front().first;//index
                 cur=q.front().second;//curr string
                 q.pop();
              //call for all the adjcent of current node
                for(int i=0;i<graph[v].size();i++){
                    tempchr=cur[graph[v][i]];
                    cur[graph[v][i]]='1';
                    if(cur==allvisit) return step+1;
                    if(!vis.count({graph[v][i],cur}))
                    {
                      q.push({graph[v][i],cur}); 
                      vis.insert({graph[v][i],cur});
                    }
                    cur[graph[v][i]]=tempchr;
                }
            }
            step++;
        }
        return -1;
    }
};
      
     
               