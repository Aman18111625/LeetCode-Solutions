class Solution {
public:
    /* Approach-1 TC:=>O(N) SC:=>O(1)
    simple find xor of given array->according to the question every element appears except one number and we know xor of same number ->0 so Xor of given array is our answer 
    int singleNonDuplicate(vector<int>& nums) {
        int Xor=0;
        int n=nums.size();
        for(int i=0;i<n;i++) Xor^=nums[i];
        return Xor;
    }
    */
    //Optimal Approach
    //TC:- O(logN) SC:-O(1)
      int singleNonDuplicate(vector<int>& nums){
          if(nums.size()==1) return nums[0];
          int low=0,high=nums.size()-2;
          while(low<=high)
          {
             int mid=(low+high)>>1;
             if(nums[mid]==nums[mid^1]) low=mid+1;
             else high=mid-1;
          }
          return nums[low];
      }
};
