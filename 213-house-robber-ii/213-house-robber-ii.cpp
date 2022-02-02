class Solution {
int houseRobber(vector<int>&nums)
  {
    int n=nums.size();
    int prev=nums[0],prev2=0;
    for(int i=1;i<n;i++)
    {
      int take=nums[i];
      if(i>1) take+=prev2;
      int nonTake=prev;
      int curr=max(take,nonTake);
      prev2=prev;
      prev=curr;
    }
    return prev;
  }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int>v2(nums.begin()+1,nums.end());
        return max(houseRobber(v1),houseRobber(v2));
    }
};