class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int freq[10001]={false};//to keep track of duplicate value
        int i=0,j=0,curr=0;//i ->beginning of subarray & j->end of subarray
        int ans=INT_MIN;//to store maximum result
        while(j<n){
          while(freq[nums[j]]){//delete from current sub-array till there's no duplicate of nums[j]
             curr-=nums[i];
             freq[nums[i]]=false;
             i++;
          }
          curr+=nums[j];//include in our subarray
          freq[nums[j]]=true;//mark as visited
          ans=max(ans,curr);//update ans with maximum till now
          j++;
        }
        return ans;
    }
};

