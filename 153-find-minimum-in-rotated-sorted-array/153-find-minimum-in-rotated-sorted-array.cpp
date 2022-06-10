class Solution {
public:
    //Brute-Force Approach:-> By Linear Search->run a for loop and find min element
    //TC:=>O(N)
    //SC:=>O(1)
    // int findMin(vector<int>& nums) {
    //     int ans=INT_MAX;
    //     for(auto num : nums) ans=min(ans,num);
    //     return ans;
    // }
   //Optimized Approach->Using Binary Search
   //TC:=>O(LogN)
   //SC:=>O(1)
   int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid,prev,next;
       while(low<=high){   
            mid = low + (high-low)/2;
            prev = (mid + n - 1)%n;
            next = (mid+1)%n;
            
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
                return nums[mid];
            else if(nums[mid]>nums[high])
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
   }
};