class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        vector<int>lis(n,1);//length of lis till ith-index
        vector<int>cnt(n,1);//count of lis of length lis[i]
        int maxLen=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(lis[j]+1>lis[i])//strictly increasing
                    {
                        lis[i]=1+lis[j];
                        cnt[i]=cnt[j];
                    }else if(lis[j]+1==lis[i]) //this means there are more subsequences of same length ending at length lis[i]
                    {
                        cnt[i]+=cnt[j];
                    }
                }
            }
            maxLen=max(maxLen,lis[i]);
         }
	
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(lis[i]==maxLen)
                 ans+=cnt[i];
        }
        return ans;
    }
};