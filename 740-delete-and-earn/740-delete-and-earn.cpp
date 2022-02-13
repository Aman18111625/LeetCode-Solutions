class Solution {
public:
  /*Tabulation:=>
  //Time-Complexity:=>O(N)
  //Space-Complexity:=>O(N)
    int deleteAndEarn(vector<int>&nums) {
      int n = 10001;
	 //take the total sum by each number
     vector<int> sum(n, 0);
     vector<int> dp(n, 0);
    
    for(auto num: nums)
        sum[num] += num;
    
    dp[0] = 0;
    dp[1] = sum[1];
    //now apply the house robbing concept
    for(int i=2; i<n; i++)
        dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
    
    return dp[n-1];
    }*/
    int result(vector<int>&arr,int i,vector<int>&dp){
        if(i==0) return arr[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=0,nottake=0;
        nottake = result(arr,i-1,dp);
        take = result(arr,i-2,dp)+arr[i];
        return dp[i]=max(take,nottake);
    }
     int deleteAndEarn(vector<int>&nums){
        int maxi=INT_MIN;
        for(auto &it : nums) maxi=max(maxi,it);
        vector<int>arr(maxi+1,0),dp(maxi+1,-1);
        for(int i:nums)
            arr[i]+=i;
       return result(arr,maxi,dp);
     }
};