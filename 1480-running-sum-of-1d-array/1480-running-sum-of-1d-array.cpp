class Solution {
public:
  //Here We need to just find prefix sum of given array
  //TC:->O(N)
  //SC:->O(1)(we're modifying the given array,not using extra array) If we're not allowed to modify the given then O(N)
    vector<int> runningSum(vector<int>& nums) {
       int n=nums.size();
       for(int i=1;i<n;i++){
         nums[i]+=nums[i-1];
       }
       return nums;
    }
};