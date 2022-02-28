class Solution {
  //MCM -> Partition DP based Question
  /*
  //Recursive + Memoization
  //TC:=>O(N*M)
  //SC:=>O(N*M)+O(N)(stack-space)
  int dp[51][51];
  int helper(vector<int>&arr,int i,int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int res=INT_MAX;
    for(int k=i;k<j;k++){
      res=min(res,helper(arr,i,k)+helper(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j]=res;
  }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        memset(dp,-1,sizeof(dp));
        return helper(values,1,n-1);
    }*/
  public:
    int minScoreTriangulation(vector<int>& arr) {
        int n=arr.size();
        int dp[n][n];
        for(int i=0;i<n;i++) dp[i][i]=0;
        for(int i=n-1;i>0;i--){
          for(int j=i+1;j<n;j++){
            int mini=INT_MAX;
            for(int k=i;k<j;k++)
            {
              int temp=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
              mini=min(temp,mini);
            }
            dp[i][j]=mini;
          }
        }
      return dp[1][n-1];
    }
};