// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
     bool isValid(int i,int j,int n,int m){
         return i<n && j<m  &&  i>=0 && j>=0 ;
     }
     
     int dfs(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&dp,int &ans){
        if(dp[i][j]!=0) return dp[i][j];
        int n=mat.size(),m=mat[0].size();
        int dir_x[]={-1,1,0,0};
        int dir_y[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nx=i+dir_x[k];
            int ny=j+dir_y[k];
            if(isValid(nx,ny,n,m)){
              if(mat[nx][ny]>mat[i][j]){
                dp[i][j]=max(dp[i][j],1+dfs(mat,nx,ny,dp,ans));
              }
            }
        }
        ans=max(ans,dp[i][j]);
        return dp[i][j];
     }
     
    int longestIncreasingPath(vector<vector<int>>& mat) {
        // Code here
        int ans=INT_MIN,n=mat.size(),m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==0){
                    dfs(mat,i,j,dp,ans);
                }
            }
        }
        return ans+1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends