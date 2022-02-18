class Solution {
public:
  /*
  // initialize dp array with maximum constraints
    int dp[2501][2501];
	// ind is current index and prev is last index what we need to compare current indexed element with
	// prev may be -1 that means its our first element of some temporary sequence
    int solve(vector<int>& v,int ind,int prev){
        int n=v.size();
        if(ind==n) return 0;
        // we cant store negative index so leave this case
        if(prev>-1 and dp[ind][prev]!=-1) return dp[ind][prev];
        int res=0;
		
		// if we dont take current element 
        res = solve(v,ind+1,prev);
		
		// if we consider current element
        if(prev==-1 or v[ind]>v[prev])
        res = max(res,1+solve(v,ind+1,ind));
		
		 // we cant store negative index so leave this case
        if(prev>-1) dp[ind][prev]=res;
        return res;
    }
    
    int lengthOfLIS(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        return solve(v,0,-1);
    }*/
   int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
          dp[i]=1;
          for(int j=0;j<i;j++){
            if(v[i]>v[j]) dp[i]=max(dp[i],1+dp[j]);
          }
        }
       return *max_element(dp.begin(),dp.end());
    }
  /*
  //TC:->O(N^2) SC:=>O(N)
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
         vector<int>lis(n,1);
        for(int i=1;i<n;i++)
        {
           for(int j=0;j<i;j++)
           {
             if(nums[i]>nums[j] && lis[i]<=lis[j])
               lis[i]=1+lis[j];
           }
        }
      return *max_element(lis.begin(),lis.end());
    }*/
};