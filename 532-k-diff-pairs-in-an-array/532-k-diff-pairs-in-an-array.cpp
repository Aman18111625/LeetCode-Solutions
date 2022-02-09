class Solution {
public:
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
           if(low==high) high++;
         }
       }
    return cnt;
    }
};

 
  