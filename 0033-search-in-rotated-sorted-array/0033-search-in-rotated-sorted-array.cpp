class Solution {
public:
    //Brute-Force Simple linear Search
    //TC:=>O(N)
    //SC:=>O(1)
    // int search(vector<int>& nums, int target) {
    //    int n=nums.size();
    //    for(int i=0;i<n;i++){
    //      if(nums[i]==target) return i;
    //    }
    //    return -1;
    // }
    //Optimal Appraoch->Using Binary Search
    //TC:=>O(logN)
    //SC:=>O(1)
    int search(vector<int>& nums, int target){
     int low=0,high=nums.size()-1;
     while(low<=high){
       int mid=(low+high)/2;
       if(nums[mid]==target) return mid;
       else if(nums[low]<=nums[mid]){
         if(target<=nums[mid] && target>=nums[low]) high=mid-1;
         else low=mid+1;
       }else{
         if(target>nums[mid] && target<=nums[high]) low=mid+1;
         else high=mid-1;
       }
     }
     return -1;
   }
};
 