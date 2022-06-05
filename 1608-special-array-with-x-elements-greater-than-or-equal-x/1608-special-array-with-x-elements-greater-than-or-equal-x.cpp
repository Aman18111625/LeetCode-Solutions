class Solution {
   int count(vector<int>&nums,int mid){
     int cnt=0;
     for(auto num: nums){
       if(num>=mid) cnt++;
     }
     return cnt;
   }
public:
    int specialArray(vector<int>& nums) {
        int maxi=INT_MIN;
        for(auto num : nums) maxi=max(maxi,num);
        int low=0,high=maxi;
        while(low<=high){
          int mid=(low+high)/2;
          int cnt=count(nums,mid);
          if(cnt==mid) return mid;
          else if(cnt>mid) low=mid+1;
          else high=mid-1;
        }
        return -1;
    }
};