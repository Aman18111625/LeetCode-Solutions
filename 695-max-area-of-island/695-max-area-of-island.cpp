class Solution {
public:
   int helper(vector<vector<int>>&grid,int i,int j,int n,int m){
     if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0) return 0;
     grid[i][j]=0;
     int ans=1;
     ans+=helper(grid,i+1,j,n,m);
     ans+=helper(grid,i-1,j,n,m);
     ans+=helper(grid,i,j+1,n,m);
     ans+=helper(grid,i,j-1,n,m);
     return ans;
   }
  
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(grid[i][j]==1){
              ans=max(ans,helper(grid,i,j,n,m));
            }
          }
        }
        return ans;
    }
};