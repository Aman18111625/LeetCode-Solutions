class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;//to keep track of duplicate value
        int i=0,j=0,curr=0;//i ->beginning of subarray & j->end of subarray
        int ans=INT_MIN;//to store maximum result
        while(j<n){
          while(st.find(nums[j])!=st.end()){//delete from current sub-array till there's no duplicate of nums[j]
             curr-=nums[i];
             st.erase(nums[i]);
             i++;
          }
          curr+=nums[j];//include in our subarray
          st.insert(nums[j]);//insert into set
          ans=max(ans,curr);//update ans with maximum till now
          j++;
        }
        return ans;
    }
};

