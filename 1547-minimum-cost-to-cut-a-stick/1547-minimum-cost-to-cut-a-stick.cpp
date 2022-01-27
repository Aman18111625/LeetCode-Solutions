class Solution {
    int dp[102][102];
    int helper(int start,int end,vector<int>&cuts,int cut_start,int cut_end)
    {
        if(cut_start>cut_end) return 0;
        if(dp[cut_start][cut_end]!=-1) return dp[cut_start][cut_end];
            int minimum = INT_MAX;
        for(int i=cut_start; i<=cut_end; i++)
            minimum = min(minimum, (end-start)+helper(start, cuts[i], cuts, cut_start, i-1)+helper(cuts[i], end, cuts, i+1, cut_end));
        return dp[cut_start][cut_end]=minimum;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
       return helper(0,n,cuts,0,cuts.size()-1);
    }
};