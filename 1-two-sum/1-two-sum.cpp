class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
          for(int j=0;j<i;j++){
            if(nums[i]+nums[j]==target) return {i,j};
          }
        }
        return ans;
    }
};