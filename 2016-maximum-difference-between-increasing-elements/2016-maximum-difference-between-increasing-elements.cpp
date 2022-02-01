class Solution {
public:
  /* TC:=>O(N^2) SC:=>O(1)
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1;
        for(int i=0;i<n;i++)
        { 
          for(int j=i+1;j<n;j++)
          {
            if(nums[j]>nums[i]) maxi=max(maxi,nums[j]-nums[i]);
          }
        }
      return maxi;
    }*/
  int maximumDifference(vector<int>& nums){
    int curr=INT_MAX,maxi=-1;
     for(auto &it: nums)
     {
       curr=min(curr,it);
       maxi=max(maxi,it-curr);
     }
      if(maxi==0) return -1;
      return maxi;
  }
};