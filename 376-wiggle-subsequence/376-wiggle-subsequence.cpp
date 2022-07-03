class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 1;
        vector<int>first(n,1),second(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
              if(nums[j]<nums[i])
              {
                  first[i]=max(first[i],second[j]+1);
              }else if(nums[j]>nums[i])
              {
                  second[i]=max(second[i],first[j]+1); 
              }
            }
        }
        return max(first.back(),second.back());
    }
};