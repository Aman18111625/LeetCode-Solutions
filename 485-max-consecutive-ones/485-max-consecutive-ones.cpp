class Solution {
public:
    //TC:=>O(N)
    //SC:=>O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,curr=0;
        for(auto &num : nums){
          if(num==1) curr++;
          else curr=0;
          maxi=max(maxi,curr);
        }
        return maxi;
    }
};