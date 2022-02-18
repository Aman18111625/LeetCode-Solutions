class Solution {
public:
  /*
Here solution has 2 cases:
1. if max_subarray lies within the indexes in a straight path.
2. if the max subarray is split, then it means that min-subbaray is present in a staright path, so answer might be total sum-min_sum;
However one edge case needs to be handeled when all values are negative min_sum==total_sum, in that case max_array in staight path iour answer.
  //Best Optimal Approach
  //Time-Complexity:=>O(N)
  //Space-Complexity:=>O(1)
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
    }*/
  
int kadane(vector<int>&nums)
{
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        sum = max(sum, nums[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
  int maxSubarraySumCircular(vector<int>&nums) {
    int maxSum1 = kadane(nums);
    int sum = 0; 
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        nums[i] = nums[i]*-1;    // nums[i]*-1 is -nums[i]
    }
    int maxSum2 = kadane(nums);
    if(maxSum1<0)//all elements are -ve
         return maxSum1;
    
    return max(maxSum1, sum + maxSum2);   // sum+maxSum2 == sum - (-maxSum2)
}
};