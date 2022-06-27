class Solution {
public:
  //for 4-directional
    int dx[4]={-1,1,0,0}; 
    int dy[4]={0,0,1,-1}; 
    void helper(int i,int j,vector<vector<int>>&grid,int cnt,int& res,int& empty){
      int n=grid.size(),m=grid[0].size();
      //base cases
      if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==-1) return ;
      if(grid[i][j]==2){
        if(empty==cnt) res++; //if we reached at target and we passed empty number of cells - this means we passed by every non-obstacle cell.
        return ;
        }
        grid[i][j]=-1; //mark as visited
        for(int k=0;k<4;k++) //call for all possible 4-direction
        {
          int nx=i+dx[k];
          int ny=j+dy[k];
          helper(nx,ny,grid,cnt+1,res,empty);
        }
        grid[i][j]=0; //backtrack->mark as unvisted
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();//no of row in grid
        int m=grid[0].size();//no of col in grid
        int x,y,empty=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1) x=i,y=j; //given there is exactly one starting cell
               else if(grid[i][j]==0) empty++; //count empty cell
            }
        }
        int res=0;
        helper(x,y,grid,0,res,empty);
        return res;
    }
};