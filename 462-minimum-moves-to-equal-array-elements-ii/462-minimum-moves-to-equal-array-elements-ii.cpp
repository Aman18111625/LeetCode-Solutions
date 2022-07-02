class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size(),mid=n/2,i=0,j=mid+1;
        int ans=0;
        while(i<mid && j<n){
            ans+=(nums[mid]-nums[i]);
            ans+=(nums[j]-nums[mid]);
            i++,j++;
        }
        while(i<mid)
          ans+=(nums[mid] - nums[i++]);
  
        return ans;
    }
};