class Solution {
public:
  /*
  //Approach-1 Using Two Pointer Method
  //Time-Complexity=>O(NLogN)(sorting)+O(N)+O(N)
  //Space-Complexity:=>O(1)
  int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());//it'll be easy to skip duplicates
        int low=0,high=1,cnt=0;
        int n=nums.size();
       while(low<n && high<n)
       {
         int diff=nums[high]-nums[low];
         if(diff==k)//find a pair so increment count
         {
           cnt++;
           high++;
           //to avoid duplicates
           while(high<n && nums[high]==nums[high-1]) high++;
         }else if(diff<k)
         {
           high++;
         }else{
           low++;
           //if(low==high) high++;
         }
       }
    return cnt;
    }*/
  //Approach-2 Using Hashmap
  //TC:=>O(N)
  //SC:=>O(N)
  int findPairs(vector<int>& nums, int k){
    unordered_map<int,int>mpp;
    for(auto &it : nums) mpp[it]++;
    int cnt=0;
    for(auto &it : mpp)
    {
      if(k==0)//in this same number is giving us pair like 3-3==0 or 1-1==0
      {
        if(it.second>1) 
        {
          cnt++;
        }
      }else 
        {
          if(mpp.find((it.first-k))!=mpp.end())
          {
            cnt++;
          }
        }
    }
      return cnt;
  }
};

 
  