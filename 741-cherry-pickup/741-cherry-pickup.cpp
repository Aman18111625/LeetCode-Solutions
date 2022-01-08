class Solution {
int helper(vector<vector<int>>&arr,vector<vector<vector<int>>>&dp,int r1,int c1,int c2,int n){
        int r2 = r1 + c1 - c2;
        //out of bound or blocked
        if(r1>=n || r2>=n || c1>=n || c2>=n || arr[r1][c1]==-1 || arr[r2][c2]==-1) return INT_MIN;
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];//already calculated
        if(r1==n-1 && c1==n-1) return arr[r1][c1];//destination
        int cherries=arr[r1][c1];
        if(r1!=r2) cherries+=arr[r2][c2];
        int hh=helper(arr,dp,r1,c1+1,c2+1,n);
        int vh=helper(arr,dp,r1+1,c1,c2,n);
        int hv=helper(arr,dp,r1,c1+1,c2,n);
        int vv=helper(arr,dp,r1+1,c1,c2+1,n);
        cherries+=max({hh,vh,hv,vv});
        return dp[r1][c1][c2]=cherries;
    }
public:
    int cherryPickup(vector<vector<int>>& grid){
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans=helper(grid,dp,0,0,0,n);
        return max(0,ans);
    }
};

      