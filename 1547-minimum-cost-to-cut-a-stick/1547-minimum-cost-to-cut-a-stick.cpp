class Solution {
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
    }
};