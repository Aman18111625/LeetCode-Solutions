class Solution {
public:
  
  //Time-Complexity:=>O(N)
  //Space-Complexity:=>O(N)
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto &num: nums) mpp[num]++;
        int n=nums.size()/2;
        for(auto &it : mpp){
          if(it.second>n) return it.first;
        }
      return -1;
    }
  //Time-COmplexity:=>O(N)
  //Space-Complexity:=>O(1)
   // int majorityElement(vector<int>& nums) {
   //      int count=0,candidates=0;
   //      for(auto &num:nums)
   //      {
   //       if(count==0) candidates=num;
   //       if(num==candidates) count++;
   //       else count--;
   //      }
   //      return candidates;
   //  }
};