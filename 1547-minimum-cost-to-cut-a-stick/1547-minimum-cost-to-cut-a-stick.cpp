class Solution {
  /*Recursive+Memoization
  int dp[101][101];
    int solve(vector<int>& cuts, int l, int r, int ci, int cj){
        if(ci>cj) return 0;
        if(dp[ci][cj]!=-1) return dp[ci][cj];
        int cost = 1e7;
        for(int k=ci; k<=cj; ++k){
            cost = min(cost, solve(cuts,l,cuts[k],ci,k-1)+solve(cuts,cuts[k],r,k+1,cj));
        }
        return dp[ci][cj] = cost+r-l;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());//all the position will be in sorted order
       return solve(cuts,0,n,0,cuts.size()-1);
    }*/
  public:
   int minCost(int n, vector<int>& arr) {
        vector<int>nums = {0};
        int size=arr.size();
        for(int i = 0; i<size;++i) nums.push_back(arr[i]);
        nums.push_back(n); 
        sort(nums.begin(),nums.end());
        int nsize=nums.size();
        vector<vector<int>>dp(nsize,vector<int>(nsize,INT_MAX));
        for(int gap = 1; gap<nsize;++gap){
            for(int i=0,j=gap; j<nsize;++j,++i){
                if(gap==1) dp[i][j] = 0;
                else{
                    int cost = INT_MAX;
                    for(int k = i+1; k<j;++k){
                        cost = min(cost,dp[i][k]+dp[k][j]);
                    }
                    cost+=nums[j]-nums[i];
                    dp[i][j] = cost;
                }
            }
        }
        return dp[0][nsize-1];
    }
};