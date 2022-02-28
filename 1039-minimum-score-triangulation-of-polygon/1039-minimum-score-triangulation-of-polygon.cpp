class Solution {
  int dp[51][51];
  int helper(vector<int>&arr,int i,int j){
    if(i>=j) return 0;
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
    }
};