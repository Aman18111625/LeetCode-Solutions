class Solution {
public:
   //Brute-Force Approach:=>Run for each queries
   //TC:=>O(M*N)
   //SC:=>O(1)
//     vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
//       vector<int>ans;
//       for(auto it: queries){
//         int val=it[0];
//         int index=it[1];
        
//         nums[index]+=val;
//         int curr_sum=0;
//         for(auto num: nums){
//           if(num&1) continue;
//           else curr_sum+=num;
//         }
//         ans.push_back(curr_sum);
//       }  
//       return ans;
//     }
   vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      vector<int>ans;
      int sum=0;
      for(auto num: nums){
        if(num&1) continue;
        else sum+=num;
      }
      for(auto it: queries){
        int val=it[0];
        int index=it[1];
        if(nums[index]%2==0){
          sum-=nums[index];
        }
        nums[index]+=val;
        if(nums[index]%2==0){
          sum+=nums[index];
        }
        ans.push_back(sum);
      }  
      return ans;
    }
};