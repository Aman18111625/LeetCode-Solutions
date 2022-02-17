class Solution {
public:
  /*Brute-Force:=>Using Min-Heap
  TC:=>O(N)
  SC:=>O(NlogN)
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
  //TC:=>O(Nlogn)
  //SC:=>O(1)
  int largestSumAfterKNegations(vector<int>&nums,int k)
  {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(auto &it : nums)
        {
          if(it<0 && k>0){
            it=(-1)*it;
            k--;
          }
        }
       for(auto &it : nums){
           sum+=it;
       }
       int mini=*min_element(nums.begin(),nums.end());
      if(k&1) sum-=2*mini;
      return sum;
  }
};