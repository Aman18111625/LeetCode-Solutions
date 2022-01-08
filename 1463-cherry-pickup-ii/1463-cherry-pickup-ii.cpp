class Solution {
    int dp[70][70][70];
   int helper(vector<vector<int>>&arr,int row,int col1,int col2,int n,int m){
       if(row<0 || row>=n || col1<0 || col1>=m ||col2<0 || col2>=m ) return 0;
       if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
       int res=arr[row][col1];
       if(col1!=col2) res+=arr[row][col2];
       if(row!=n-1){
           int maxi=0;
           for(int j1=col1-1;j1<=col1+1;j1++){
               for(int j2=col2-1;j2<=col2+1;j2++){
                   maxi=max(maxi,helper(arr,row+1,j1,j2,n,m));
               }
           }
           res+=maxi;
       }
       return dp[row][col1][col2]=res;
   }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return helper(grid,0,0,m-1,n,m);
    }
};
 
    
  
    