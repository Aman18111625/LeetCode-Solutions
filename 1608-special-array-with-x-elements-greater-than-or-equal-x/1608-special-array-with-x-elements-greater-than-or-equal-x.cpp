class Solution {
  public:
  //Brute-Force Appraoch->simply run nested loop and check for every number ,how many are greater or equal to that number
  //TC:=>O(N^2)
  //SC:=>O(1)
    int specialArray(vector<int>& nums) {
        for(int i=1;i<1000;i++){
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]>=i) cnt++;
            }
            if(cnt==i) return i;
        }
        return -1;
    }
  
//    int count(vector<int>&nums,int mid){
//      int cnt=0;
//      for(auto num: nums){
//        if(num>=mid) cnt++;
//      }
//      return cnt;
//    }
// public:
//     int specialArray(vector<int>& nums) {
//         int maxi=INT_MIN;
//         for(auto num : nums) maxi=max(maxi,num);
//         int low=0,high=maxi;
//         while(low<=high){
//           int mid=(low+high)/2;
//           int cnt=count(nums,mid);
//           if(cnt==mid) return mid;
//           else if(cnt>mid) low=mid+1;
//           else high=mid-1;
//         }
//         return -1;
//     }
};