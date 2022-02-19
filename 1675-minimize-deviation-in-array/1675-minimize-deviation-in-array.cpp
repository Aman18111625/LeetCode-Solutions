class Solution {
public:
    int minimumDeviation(vector<int>&nums) {
        int n=nums.size();
        int mini=INT_MAX;
        priority_queue<int>pq;//maxHeap
        for(int i=0;i<n;i++){
            if(nums[i]&1) nums[i]*=2;//if odd then we'll multiply by 2 
            mini=min(mini,nums[i]);//take care of minimum after performing operation
            pq.push(nums[i]);
        } 
        int ans=INT_MAX;
        while(!pq.empty() && pq.top()%2==0){
           int maxi=pq.top(); pq.pop();
            ans=min(ans,maxi-mini);
            mini=min(mini,maxi/2);
            pq.push(maxi/2);
        }
      return min(ans,(pq.top()-mini));
    }
};
