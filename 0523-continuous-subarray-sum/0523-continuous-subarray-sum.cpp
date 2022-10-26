class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // int n=nums.size();
        // for(int i=0;i<n-1;i++){
        //   int sum=nums[i];
        //   for(int j=i+1;j<n;j++){
        //     sum+=nums[j];
        //     if(sum%k==0) return true;
        //   }
        // }
        // return false;
        int n=nums.size();
        if(n<2) return false; //we need to find a subarray atleast size->2
        unordered_map<int,int>mpp; 
         //Why to insert <0,-1> for the hashmap  
        // <0,-1> can allow it to return true when the runningSum%k=0,
        //ok - but why -1?
        //-1 is good for storing for 0 because - it will remove the case where we consider only the first element which alone may be a multiple as 0-(-1) is not greater than 1
        // In addition, it also avoids the first element of the array is the multiple of k, since 0-(-1)=1 is not greater than 1.
        mpp[0]=-1;
        int curr_sum=0;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            if(k) curr_sum=curr_sum%k;
            if(curr_sum==0 and i) return true;
            if(mpp.find(curr_sum)!=mpp.end())
            {
                if(i-mpp[curr_sum]>1) return true;
            }
            else mpp[curr_sum]=i;
        }
        return false;
    }
};