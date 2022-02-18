class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int maxSum=INT_MIN,minSum=INT_MAX;
        int currMax=0,currMin=0,sum=0;
        for(int i=0;i<n;i++){
          sum+=nums[i];
          
          currMax+=nums[i];
          if(currMax<nums[i]) currMax=nums[i];
          maxSum=max(maxSum,currMax);
          
          currMin+=nums[i];
          if(currMin>nums[i]) currMin=nums[i];
          minSum=min(minSum,currMin);
        }
       if(sum==minSum)//all are -ve
       {
         return maxSum;
       }
      return max(maxSum,sum-minSum);
    }
};