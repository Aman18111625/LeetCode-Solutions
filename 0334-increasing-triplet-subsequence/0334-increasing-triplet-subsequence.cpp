class Solution {
public:
    // Brute-Force :
//     bool increasingTriplet(vector<int>&nums) {
//       int n=nums.size();
//       vector<int>leftMin(n),rightMax(n);
//       leftMin[0]=nums[0];
//       for(int i=1;i<n;i++) leftMin[i]=min(leftMin[i-1],nums[i]);
//       rightMax[n-1]=nums[n-1];
//       for(int i=n-2;i>=0;i--){
//         rightMax[i]=max(rightMax[i+1],nums[i]);
//       }
      
//       for(int i=1;i<n-1;i++){
//         if(leftMin[i-1]<nums[i]<rightMax[i+1]) return true;
//       }
//       return false;
//     }
  
  //Optimized Approach
   bool increasingTriplet(vector<int>& nums) {
         int left=INT_MAX;
         int mid=INT_MAX;
         int n=nums.size();
         for(int i=0;i<n;i++){
            if(nums[i]>mid) return true;
            else if(nums[i]>left and nums[i]<mid) mid=nums[i];
            else if(nums[i]<left) left=nums[i];
         }
        return false;
    }
};