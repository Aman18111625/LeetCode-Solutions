class Solution {
  int dfs(vector<vector<int>>&stones,int index,vector<bool>&vis,int&n){
        vis[index]=true;
        int res=0;
        for(int i=0;i<n;i++){
          //if it's not visited and share same or same column than we need to remove that stone that's why  ans= next dfs + 1
          if(!vis[i] && (stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                res +=(dfs(stones,i,vis,n) + 1);
        }
        return res;
   }

public:
    int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
        vector<bool>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i])
             ans+=dfs(stones,i,vis,n);
        }
        return ans;
    }
};