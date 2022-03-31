class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int start=0,end=0,mid;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            start=max(start,nums[i]);
            end+=nums[i];
        }
        while(start<end)
        {
             mid=start+(end-start)/2;
            int sum=0;
            int pieces=1;
            for(auto &num : nums)
            {
                if(num+sum>mid)
                {
                  pieces++;
                  sum=num;  
                }
                else
                {
                    sum+=num;
                }
            }
            if(pieces>m)
                start=mid+1;
            else end=mid;
        }
        
        return end;
      
    }
};