class Solution {
public:
    const int mod=1e9+7;
//Recursive+Memoization
//     int dp[51][51][51];
//     int dfs(int i,int j,int m,int n,int maxMove){
//      if(i<0 or i>=m or j<0 or j>=n) return 1;
//      if(maxMove==0) return 0;
//      if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove]%mod;
//       int ans=0;
//       ans=(ans%mod+dfs(i+1,j,m,n,maxMove-1)%mod);
//       ans=(ans%mod+dfs(i-1,j,m,n,maxMove-1)%mod);
//       ans=(ans%mod+dfs(i,j+1,m,n,maxMove-1)%mod);
//       ans=(ans%mod+dfs(i,j-1,m,n,maxMove-1)%mod);
//      return dp[i][j][maxMove]=ans%mod;
//    }
  
//     int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//         memset(dp,-1,sizeof(dp));
//         return dfs(startRow,startColumn,m,n,maxMove);
//     }
  
  //all 4-adjacent direction
  vector<vector<int>>dir={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  
  bool outOfBounds(int m,int n,int i,int j){
    return (i<0 or j<0 or i>=m or j>=n);
  }
  
int findPaths(int m, int n, int maxMove, int r, int c) {
  uint dp[51][51][51]{};
	for(int M = 1; M <= maxMove; M++){ // iterate for all available moves
	 	for(int i = 0; i < m; i++){ 
			for(int j = 0; j < n; j++){ 
				for(int k = 0; k < 4; k++){  // for each cell, try all 4 possible moves
           int x=i+dir[k][0];
           int y=j+dir[k][1];
           if(outOfBounds(m,n,x,y)) dp[i][j][M]++;
           else dp[i][j][M]=(dp[i][j][M]%mod+dp[x][y][M-1]%mod);
        }	
      }
    }
  }
	return dp[r][c][maxMove] % mod;
}
  
};