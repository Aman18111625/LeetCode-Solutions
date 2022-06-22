class Solution {
public:
//DFS Approach
//     void dfs(vector<vector<char>>&grid,int i,int j){
//       if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size()) return ;
//       // return if current position is of water or is already visited
//       if(grid[i][j] == '2' || grid[i][j] == '0') return;
//       grid[i][j]='2';
//       dfs(grid,i+1,j);
//       dfs(grid,i-1,j);
//       dfs(grid,i,j+1);
//       dfs(grid,i,j-1);
//     }   
  
//     int numIslands(vector<vector<char>>& grid) {
//       int ans=0,n=grid.size(),m=grid[0].size();
//       for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//           if(grid[i][j]=='1'){
//             dfs(grid,i,j);
//             ans++;
//           }
//         }
//       }
//       return ans;
//     }
  
  //BFS 
  int numIslands(vector<vector<char>>& grid) {
       int m = grid.size();
       if(m==0) return 0;
       int n =  grid[0].size() ;
       int ans = 0;
       int dir[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
              if (grid[i][j] == '1') {
                  ans++;
                  grid[i][j] = '0';
                  queue<pair<int, int>>todo;
                  todo.push({i, j});
                  while (!todo.empty()) {
                  pair<int, int> p = todo.front();
                  todo.pop();
                  for (int k = 0; k < 4; k++) {
                      int r = p.first + dir[k], c = p.second +dir[k + 1];
                      if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1'){
                                grid[r][c] = '0';
                                todo.push({r, c});
                        }
                      }
                  }
                }
            }
        }
        return ans;
    }
};