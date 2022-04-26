class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=nums[0];
        while(true){
          if(nums[i]<0) return i;
          nums[i]=-nums[i];
          i=abs(nums[i]);
        }
        return -1;
    }
};