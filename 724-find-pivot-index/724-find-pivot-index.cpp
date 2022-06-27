class Solution {
public:
  //Brute-Force Approach:-> For every index find leftSum and RightSum.
  //TC:=>O(N^2)
  //SC:=>O(1)
    // int pivotIndex(vector<int>& nums) {
    //      int n=nums.size();
    //      for(int i=0;i<n;i++){
    //        int leftSum=0;
    //        for(int j=0;j<i;j++) leftSum+=nums[j];
    //        int rightSum=0;
    //        for(int j=i+1;j<n;j++) rightSum+=nums[j];
    //        if(leftSum==rightSum) return i;
    //      }
    //      return -1;
    // }
 
  //Better Approach:->find prefix and suffix sum
  //TC:=>O(3*N)
  //SC:=>O(2*N)
  int pivotIndex(vector<int>& nums) {
         int n=nums.size();
         vector<int>prefix(n),suffix(n);
         prefix[0]=nums[0];
         for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+nums[i];
    
         suffix[n-1]=nums[n-1];
         for(int i=n-2;i>=0;i--){
           suffix[i]=suffix[i+1]+nums[i];
         }
        
         for(int i=0;i<n;i++){
           if(prefix[i]==suffix[i]) return i;
         }
         return -1;
    }
};