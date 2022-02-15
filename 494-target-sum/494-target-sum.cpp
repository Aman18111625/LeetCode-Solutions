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
  /*
  //Recursive + Memoization
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
    }*/
  //This is similar to count number of way to divide to array in two subset such that sum equal to target
    int countSubsets(vector<int>& nums, int n, int sum)
    {
        int dp[n + 1][sum+ 1];
      //intialization
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(i == 0) dp[i][j] = 0;
                if(j == 0)  dp[i][j] = 1;
            }
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(nums[i - 1] <= j)
                 dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                  dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[n][sum];  
    }
    public:
    int findTargetSumWays(vector<int>& nums, int target)
     {
         target = abs(target);
         int sum = 0;
         for(auto& num : nums) sum += num;
          if(sum < target or ((sum + target)&1))  return 0;
          int M = (sum + target)/2;
         return countSubsets(nums, nums.size(), M);
     }
};