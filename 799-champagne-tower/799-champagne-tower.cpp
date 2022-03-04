class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
         double dp[102][102]={0.0};
         dp[0][0]=poured;//all poured in the topmost glass
         for(int i=0;i<query_row;i++){
           for(int j=0;j<=i;j++){
             if(dp[i][j]>=1){
               double flow=(dp[i][j]-1)/2.0;
               dp[i+1][j]+=flow;
               dp[i+1][j+1]=flow;
               dp[i][j]=1.0;
             }
           }
         }
      return min(1.0000,dp[query_row][query_glass]);//min of 1,because of when all glasses will be completely filled
    }
};