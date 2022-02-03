class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.empty()) return res;
        int sum,rem,n=nums.size();
        sort(nums.begin(),nums.end());
       for(int i=0;i<n-3;i++)
       {
         if(i>0 && nums[i]==nums[i-1]) continue;///skip the duplicate values
         for(int j=i+1;j<n-2;j++)
         {
            if(j>i+1 && nums[j]==nums[j-1]) //skip the duplicate values
                continue;
           for(int k=j+1;k<n-1;k++)
           {
              if(k>j+1 and nums[k]==nums[k-1]) // skip the duplicate value
                  continue;
             rem=target-nums[i]-nums[j];
             for(int l=k+1;l<n;l++)
             {
                if(l>k+1 and nums[l]==nums[l-1])//skip the duplicate values
                  continue;
               int sum=nums[l]+nums[k];
               if(sum>rem) break;
               else if(sum==rem)
               {
                  vector<int>temp(4,0);
                   temp[0]=nums[i];
                   temp[1]=nums[j];
                   temp[2]=nums[k];
                   temp[3]=nums[l];
                 res.push_back(temp);
               }
             }
           }
         }
       }
      return res;
    }
};
