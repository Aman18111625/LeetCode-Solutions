class Solution {
public:
  /*Brute-Force:=>Using Min-Heap
  TC:=>O(N)
  SC:=>O(N)
    int largestSumAfterKNegations(vector<int>& nums, int k) {
       priority_queue<int,vector<int>,greater<int>>pq;//min-heap
       for(auto &it : nums)
       {
         pq.push(it);
       }
      while(k--)
      {
        int temp=-pq.top();
        pq.pop();
        pq.push(temp);
      }
      int sum=0;
      while(!pq.empty()) sum+=pq.top(),pq.pop();
      return sum;
    }*/
  int largestSumAfterKNegations(vector<int>&nums,int k)
  {
          int i=0;
        while(k)
        {   
            sort(nums.begin(),nums.end());
            if(nums[i]<0)
            {
                nums[i]= -nums[i];
                k--;
            }
            else if(nums[i]==0)
            {
                nums[i]=nums[i];
                k=k-k;
            }
            else
            {
                nums[i]=-nums[i];
                k--;
            }
        }
        int sum=0;
        for(auto i:nums)
            sum+=i;
        return sum;
  }
};