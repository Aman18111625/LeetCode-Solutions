class Solution {
  public:
   bool topo(int start,vector<int>adj[], int n,bool *vis, bool *s)
    {
        vis[start]=true;
        s[start]=true;
        for(int v: adj[start])
        {
            if(!vis[v])
            {
                if(topo(v,adj,n,vis,s))
                return true;
            }
            else if(s[v])
                return true;
        }
        s[start]=false;
        return false;
    }
    
    
    bool canFinish(int courses, vector<vector<int>>& prerequisites) 
    {
        int n =courses;
        vector<int>adj[n];
        for(int i=0;i<prerequisites.size();i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        bool s[n], vis[n];
        for(int i=0;i<n;i++) 
        {
            vis[i]=false;
            s[i]=false;
        }
        
        for(int i=0;i<n;i++)
        {
            if(topo(i,adj,n,vis,s)) //if cycle detected then return false
                return false;
        }
        
        return true;
        
    }
    
  
  /*BFS
    bool canFinish(int num, vector<vector<int>>&a) {
         int n=a.size();
         int cnt=0;
        vector<int>in(num,0);
        vector<int> adj[num +1];
        queue<int> q;
       for(int i=0;i<n;i++) adj[a[i][1]].push_back(a[i][0]);//storing directed graph
        
        for(int i=0;i<n;i++)
        {
            in[a[i][0]]++;// calculating indegree
        }
        
        for(int i=0;i<num ;i++)
        {
            if(in[i]==0) q.push(i); //if indegree==0, push in queue
        }
        
        while(!q.empty())
        {
            int temp=q.front();
            for(auto it: adj[temp])
            {
                in[it]--;
                if(in[it]==0) q.push(it);
            }
           cnt++; q.pop();
        }
        
        return cnt==num;
    }*/
  
};
 
      
        
      