class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& p) {
        vector<int>adj[num];
        vector<int>in(num,0);
        queue<int>q;
        //store as a directed graph
        for(int i=0;i<p.size();i++)  
          adj[p[i][1]].push_back(p[i][0]); 
        //if there is a edge u->v then indegree of v->1 and u->0
        for(int i=0;i<p.size();i++) in[p[i][0]]++;
        //push into queue that have 0 indegree
        for(int i=0;i<in.size();i++)
        {
            if(in[i]==0) q.push(i);
        }
        vector<int>topo;
        //simple BFS 
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto it : adj[temp])
            {
                 in[it]--;
                if(in[it]==0) q.push(it);
            }
               topo.push_back(temp);
        }
        if(topo.size()!=num) topo.clear(); 
        return topo;
    }
};