class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
          int rem=target-nums[i];
          if(mpp.find(rem)!=mpp.end()) return {mpp[rem],i+1};
          else mpp[nums[i]]=i+1;
        }
        return {-1,-1};
    }
};