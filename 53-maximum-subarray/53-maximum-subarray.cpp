class Solution {
public:
    //Brute-Force Approach
    //TC:=>O(N^2)
    //SC:=>O(1)
    // int maxSubArray(vector<int>& nums) {
    //   int n=nums.size();
    //   int maxi=INT_MIN;
    //   for(int i=0;i<n;i++){
    //     int curr=0;
    //     for(int j=i;j<n;j++){
    //       curr+=nums[j];
    //       maxi=max(maxi,curr);
    //     }
    //   }
    //   return maxi;
    // }
    int maxSubArray(vector<int>&nums){
       int curr_sum=0;
       int max_sum=INT_MIN;
       int n=nums.size();
       for(int i=0;i<n;i++){
         curr_sum+=nums[i];
         if(curr_sum>max_sum) max_sum=curr_sum;
         if(curr_sum<0) curr_sum=0;
       }
       return max_sum;
    }
};