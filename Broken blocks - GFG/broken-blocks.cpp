// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int solve(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&dp){
        if(i==mat.size() || j<0 || j==mat[0].size() || mat[i][j]==-1) return 0;
        int a=0,b=0,c=0;
        if(dp[i][j]!=-1) return dp[i][j];
        a=solve(mat,i+1,j,dp);
        b=solve(mat,i+1,j-1,dp);
        c=solve(mat,i+1,j+1,dp);
        return dp[i][j]=mat[i][j]+max({a,b,c});
    }
public:
int MaxGold(vector<vector<int>>&matrix){
    // Code here
    int m=matrix.size(),n=matrix[0].size();
    int res=0;
    vector<vector<int>>dp(m,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        res=max(res,solve(matrix,0,i,dp));
    }
    return res;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends