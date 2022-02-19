class Solution {
public:
  /*Using Priority_Queue
  //Previosuly Asked in Amazon and Samsung
    int minimumDeviation(vector<int>&nums) {
        int n=nums.size();
        int mini=INT_MAX,maxi=INT_MIN;
        priority_queue<int>pq;//maxHeap->using this because it'll give us everytime max element in O(logn) time 
      //we can perform 2 operations so *2->increasing and /2->decreasing so what i'll do here *2 to all odd so at the i have to perform only one operations
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
    }*/
  //Using Set->instead of using priority_queue we can use set too.
     int minimumDeviation(vector<int>& nums) {
        set<int>st;
        for(auto &it : nums) 
        {
          if(it&1) st.insert(it*2);
          else st.insert(it);
        }
        int diff = *st.rbegin() - *st.begin();//*st.rbegin()->max element & *st.begin()->min element
        while(*st.rbegin() % 2 == 0)
        {
            int x = *st.rbegin();
            st.erase(x);
            st.insert(x/2);
            diff = min(diff, *st.rbegin() - *st.begin());
        }
        return diff;
    }
};
