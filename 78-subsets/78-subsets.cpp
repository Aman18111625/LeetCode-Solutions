class Solution {
   void helper(vector<int>&nums,int idx,int &size,vector<vector<int>>&ans,vector<int>&ds)
   {
     if(idx==size)
     {
       ans.push_back(ds);
       return ;
     }
     //for every elements we have two choices either we can take it or not take it
     //option1
     ds.push_back(nums[idx]);
     helper(nums,idx+1,size,ans,ds);
     //option2
     ds.pop_back();
     helper(nums,idx+1,size,ans,ds);
   }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        if(nums.empty()) return ans;
        int size=nums.size();
        helper(nums,0,size,ans,ds);
      return ans;
    }
};