class Solution {
public:
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
    }
};
 
      
        
      