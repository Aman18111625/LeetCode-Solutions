class Solution {
public:
    void moveZeroes(vector<int>& nums) {
          int n=nums.size();
          if(n==1) return ;
             int i=0,a=0;
          while(i<n)
          {
               if(nums[i]!=0)
               {
                   swap(nums[i],nums[a]);
                   a++;
               }
             i++;
          }
    }
};