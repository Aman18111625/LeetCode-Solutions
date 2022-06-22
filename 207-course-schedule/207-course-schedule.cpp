class Solution {
  public:
  //DFS Traversal
   bool topo(int start,vector<int>adj[], int n,vector<bool>&vis, vector<bool>&s){
        vis[start]=true;
        s[start]=true;
        for(int it: adj[start]){
            if(!vis[it]){
              if(topo(it,adj,n,vis,s))
                  return true;
            }
            else if(s[it])
                return true;
        }
        s[start]=false;
        return false;
    }
    
    
    bool canFinish(int courses, vector<vector<int>>& pre){
        int n =courses;
        vector<int>adj[n];
        for(auto it : pre)
            adj[it[1]].push_back(it[0]);
        
        vector<bool>s(n,false),vis(n,false);
        for(int i=0;i<n;i++){
            if(topo(i,adj,n,vis,s)) //if cycle detected then return false
                return false;
        }
        return true;
    }
    
  
//BFS Traversal using Kah
//     bool canFinish(int num, vector<vector<int>>&a) {
//         int n=a.size(),cnt=0;
//         vector<int> in(num,0) , adj[num +1];
//         queue<int> q;
//         for(int i=0;i<n;i++) 
//           adj[a[i][1]].push_back(a[i][0]);//storing directed graph
        
//         for(int i=0;i<n;i++)
//            in[a[i][0]]++;// calculating indegree
        
        
//         for(int i=0;i<num ;i++){
//             if(in[i]==0)
//               q.push(i); //if indegree==0, push in queue
//         }
        
//         while(!q.empty()){
//             int temp=q.front(); q.pop();
//             for(auto &it: adj[temp]){
//                 in[it]--;
//                 if(in[it]==0) q.push(it);
//             }
//             cnt++;
//         }  
//        return cnt==num;
//     }
  
};
 
      
        
      