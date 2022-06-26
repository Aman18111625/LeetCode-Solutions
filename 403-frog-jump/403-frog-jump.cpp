class Solution {
  int dp[2001][2001];
  bool helper(vector<int>&stones,int start,int jump)
  {
    if(start==stones.size()-1) return true;//we reach the (n-1)th position
    if(dp[start][jump]!=-1) return dp[start][jump];
    bool flag=false;
    int curr=stones[start];
    for(int i=start+1;i<stones.size() && !flag;i++)
    {
      int need=stones[i]-curr;
      if(need-jump>1) break;
      else if(need-jump>=-1 && need-jump<=1)
      {
        flag=helper(stones,i,need);
      }
    }
    return dp[start][jump]=flag;
  }
public:
    bool canCross(vector<int>& stones) {
      int n=stones.size();
      if(n==2) return stones[1]<=1;
      memset(dp,-1,sizeof(dp));
      return helper(stones,0,0);
    }
};

 
    