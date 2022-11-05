class Solution {
  //TC:=>O(2^N*K) where k is average length 
  //SC:=>O(k*X) where k is the average length and x is the no. of combinations
  void helper(vector<int>&nums,int ind,int target,vector<vector<int>>&ans,vector<int>&ds){
    if(ind<0) return ;
    if(target==0)
    { 
      ans.push_back(ds);
      return ;
    }
    //for every index we have two choices either we can choose it or not it
    //we'll ignore value that are greater than target because they didn't give us answer
    if(nums[ind]<=target)
    {
     //option 1-> take
     ds.push_back(nums[ind]);
     helper(nums,ind,target-nums[ind],ans,ds);
     ds.pop_back();//backtrack
    }
    //option2 -> NotTake
     helper(nums,ind-1,target,ans,ds);
  }
public:
    vector<vector<int>>combinationSum(vector<int>&candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        helper(candidates,n-1,target,ans,temp);
       return ans;
    }
};
       