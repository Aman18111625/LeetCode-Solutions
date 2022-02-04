class Solution {
public:
  /*
  //Brute-Force =>get TLE 
  //Time-Complexity : O(N^2) 
  //Space-Complexity: O(1)
  //generate all the subarray and take maximum length of them in which cnt0==cnt1;
    int findMaxLength(vector<int>& nums) {
        if(nums.size()<2) return 0;//base case 
        int res=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            int cnt0=0,cnt1=0;
          for(int j=i;j<n;j++)
          {
            if(nums[j]==0) cnt0++;
            else  cnt1++;
            if(cnt0==cnt1) res=max(res,2*cnt0);
          }
        }
      return res;
    }*/
   int findMaxLength(vector<int>& nums) {
        int res=0,n=nums.size();
        if(n<2) return res;
        unordered_map<int,int>mpp;
        int sum=0;
        for(int i=0;i<n;i++)
        {
           if(nums[i]==1) sum++;
           else sum--;
           if(sum==0 && res<i+1) res=i+1; 
           else if(mpp.find(sum)!=mpp.end()) res=max(res,i-mpp[sum]);
           else mpp[sum]=i;
        }
      return res;
    }
  
};
      
       