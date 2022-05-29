class Solution {
public:
  //Brute-Force Solution->check for every pairs if sum of these two equal to target then simply return their respective indices
  //TC:=>O(N^2)
  //SC:=>O(1)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     vector<int>ans;
    //     for(int i=0;i<n;i++){
    //       for(int j=0;j<i;j++){
    //         if(nums[i]+nums[j]==target) return {i,j};
    //       }
    //     }
    //     return ans;
    // }
  //Better Solution->Using Hashmap
  //TC:=>O(N)
  //SC:=>O(N)
  vector<int> twoSum(vector<int>& nums, int target){
    vector<int>ans;
    unordered_map<int,int>mpp;
    int n=nums.size();
    for(int i=0;i<n;i++){
      int rest=target-nums[i];
      if(mpp.find(rest)!=mpp.end()) return {i,mpp[rest]};
      mpp[nums[i]]=i;
    }
    return ans;
  }
};