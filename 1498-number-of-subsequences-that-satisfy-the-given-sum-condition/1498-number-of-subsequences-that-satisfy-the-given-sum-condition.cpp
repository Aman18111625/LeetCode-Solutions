class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//we need to sort because it'll help us to get minimum at starting and maximum at end
        int ans=0,n=nums.size(),mod=1e9+7;
        int start=0,end=n-1;
        vector<int>pow(n,1);
       for(int i=1; i<n; i++)
          pow[i] = (pow[i-1] * 2)%mod;   
    
        while(start<=end)
        {
          if(nums[start]+nums[end]<=target)
          {
            ans=(ans+pow[end-start])%mod;
            start++;
          }else 
          {
            end--;
          }
        }
      return ans;
    }
};


    
   