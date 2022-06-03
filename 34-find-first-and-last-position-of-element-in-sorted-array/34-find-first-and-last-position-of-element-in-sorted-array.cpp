class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
           int mid=low+(high-low)/2;
           if(nums[mid]==target){
               int low1=mid,high1=high;
               int low2=low,high2=mid;
             
               //for finding 1st position
               while(low1<=high1){
                   int mm = low1+(high1-low1)/2;
                    if(nums[mm] == target){
                        low1 = mm+1;
                    }
                    else{
                        high1 = mm-1;
                    }
               }
              
               //for finding 2nd position
               while(low2<=high2){
                   int mm = low2+(high2-low2)/2;
                    if(nums[mm] == target){
                        high2 = mm-1;
                    }
                    else{
                        low2 = mm+1;
                    } 
               }
                
               return {low2,high1};
           }else if(nums[mid]>target){
             high=mid-1;
           }else{
             low=mid+1;
           }
        }
        return {-1,-1};
    }
};