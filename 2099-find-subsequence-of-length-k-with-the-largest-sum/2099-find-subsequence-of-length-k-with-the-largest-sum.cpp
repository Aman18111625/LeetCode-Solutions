class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq,pq2;
      //min-Heap ->where we'll store value as key and key as index
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
            if(pq.size()>k)//we have to only take care about k-length
                pq.pop();
        }
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            pq2.push({x.second,x.first});
        }
        vector<int>res;
        while(!pq2.empty())
        {
            res.push_back(pq2.top().second);
            pq2.pop();
        }
        
        return res;
    }
};