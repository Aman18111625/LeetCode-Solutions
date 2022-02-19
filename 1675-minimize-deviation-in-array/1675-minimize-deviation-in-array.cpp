class Solution {
public:
  //Asked in Amazon and Samsung
    int minimumDeviation(vector<int>&nums) {
        int n=nums.size();
        int mini=INT_MAX,maxi=INT_MIN;
        priority_queue<int>pq;//maxHeap
        for(int i=0;i<n;i++){
            if(nums[i]&1) nums[i]*=2;//if odd then we'll multiply by 2 
            mini=min(mini,nums[i]);//take care of minimum after performing operation
           maxi=max(maxi,nums[i]);//take care of maximum
            pq.push(nums[i]);
        } 
        int ans=maxi-mini;
        while(pq.top()%2==0){
            int maxi=pq.top(); 
             pq.pop();
            ans=min(ans,maxi-mini);
            maxi>>=1;
            mini=min(mini,maxi);
            pq.push(maxi);
        }
      return min(ans,(pq.top()-mini));
    }
};
