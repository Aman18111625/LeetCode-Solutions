class Solution {
public:
     //Efficient Approach
     //Using Hashmap
     //TC:=>O(N)
     //SC:=>O(N)
    int subarraySum(vector<int>& nums, int k) {
        int count=0,sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
          sum+=nums[i];
         if(sum==k) count++;
         int target_2=sum-k;
         if(mp.find(target_2)!=mp.end())
         {
           count+=mp[target_2];
         }
         mp[sum]++;
        }
    return count;
    }
    /*
  //Brute-Force 
  //Generate all the subarray & check whether sum==k or not
  //TC:=>O(N^2)
  //SC:=>O(1)
       int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++){  //starting index decided by this loop
           int sum = 0;
            for(int win = 1; win <= n-i; win++){ //window size is decided by this loop
                sum += nums[win-1+i];
                if(sum == k) ans++;
            }
        }
        return ans;
    }*/
};