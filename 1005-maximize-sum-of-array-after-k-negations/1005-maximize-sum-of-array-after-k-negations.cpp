class Solution {
public:
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
    }
};