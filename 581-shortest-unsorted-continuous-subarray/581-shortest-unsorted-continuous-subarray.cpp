class Solution {
public:
  // Brute-Force ->Using Sorting 
  //TC:=>O(NLOGN) SC:=>O(1)
    // int findUnsortedSubarray(vector<int>& nums) {
    //     vector<int>arr(nums.begin(),nums.end());
    //     sort(arr.begin(),arr.end());
    //     int n=nums.size();
    //     int i=0,j=n-1;
    //     while(i<n && nums[i]==arr[i]) i++;
    //     while(j>=0 && nums[j]==arr[j]) j--;
    //     if(i<j) return (j-i+1);
    //     return 0;
    // }
    int findUnsortedSubarray(vector<int>& nums) {
        int ans = 0;  
        // Two pointers
        int i=0,j=nums.size()-1;
        int curr_max=INT_MAX,curr_min=INT_MIN;
        // Initialize end to -1, if we have all sorted in ascending order, then end-start+1 = -1+0+1 = 0 
        int start=0,end=-1;
        while(j >= 0){
            // Check if the "num[start]" is greater than the minimum element so far
            if(nums[i] >= curr_min) curr_min = nums[i];
            else end = i; // m contains the 

            // Check if the "num[end]" is less than the maximum element so far
            if(nums[j] <= curr_max) curr_max = nums[j];
            else start = j;

            ++i;
            --j;
        }
        return end - start + 1;
    }
};