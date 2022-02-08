class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto &it : nums)
          mini=min(mini,it);
      
        int ans=0,n=nums.size();
         for(int i=n-1;i>=0;i--)
             ans+=(nums[i]-mini);
      
      return ans;
    }
};