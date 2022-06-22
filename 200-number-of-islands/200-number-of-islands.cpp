class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i,int j){
      if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size()) return ;
      // return if current position is of water or is already visited
      if(grid[i][j] == '2' || grid[i][j] == '0') return;
      grid[i][j]='2';
      dfs(grid,i+1,j);
      dfs(grid,i-1,j);
      dfs(grid,i,j+1);
      dfs(grid,i,j-1);
    }   
  
    int numIslands(vector<vector<char>>& grid) {
      int ans=0,n=grid.size(),m=grid[0].size();
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid[i][j]=='1'){
            dfs(grid,i,j);
            ans++;
          }
        }
      }
      return ans;
    }
};