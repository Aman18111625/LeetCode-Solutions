class Solution {
  /*Recursive:=>
    Time-Complexity:=>O(4^N) 
    Space-Complexity:=>O(N)(stack-space)
    int cnt;
    void helper(vector<int>&nums,int index,int n,string sign,int target,int sum)
    {
        if(index==n and sum==target) 
        {
            cnt++;
            return ;
        }
        if(index>=n) return;
          if(sign=="+")  
          {
              helper(nums,index+1,n,"+",target,sum+nums[index]);
              helper(nums,index+1,n,"-",target,sum+nums[index]);
         }
         if(sign=="-")  
          {
              helper(nums,index+1,n,"+",target,sum-nums[index]);
              helper(nums,index+1,n,"-",target,sum-nums[index]);
         }
    }
public:
    int findTargetSumWays(vector<int>&nums, int target) {
        int n=nums.size();
         cnt=0;
        helper(nums,0,n,"+",target,0);
        helper(nums,0,n,"-",target,0);
      return cnt/2;
    }*/
     int dp[21][2001];
    int helper(vector<int>&nums,int index,int n,int target,int sum)
    {
        if(index==n) return sum==target;
        if(dp[index][sum+1000]!=-1) return dp[index][sum+1000];//adding 1000 because  negative sum can be possible
         int cnt=0;
         cnt+=helper(nums,index+1,n,target,sum+nums[index]);
         cnt+=helper(nums,index+1,n,target,sum-nums[index]);
         return dp[index][sum+1000]=cnt;
    }
  public:
    int findTargetSumWays(vector<int>&nums, int target) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
      return  helper(nums,0,n,target,0);
    }
};