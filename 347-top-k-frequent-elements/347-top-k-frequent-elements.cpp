class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        if(n==1 and k==1) return nums;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
            mpp[nums[i]]++;
                  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it : mpp)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};