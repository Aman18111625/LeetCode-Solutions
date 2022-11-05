class Solution {
  //Time Complexity:O(2^N*k)
  //SC:=>O(2^N*K)
  //Brute-Force Approach
  //step1->sort the array because sorting will help us to skip duplicates
  //step2-> 
  //a. base condtion ->target==0 .
  //b. run a for loop from ind to n & if arr[i]>target simply break else for every element we have to condition either we can pick it or not pick it.
    void helper(vector<int>&arr,int ind,int target,vector<vector<int>>&ans,vector<int>&ds){
      if(target==0){
        ans.push_back(ds);
        return;
      }
      for(int i=ind;i<arr.size();i++){
        if(i!=ind && arr[i]==arr[i-1]) continue;//skip duplicates
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        helper(arr,i+1,target-arr[i],ans,ds);
        ds.pop_back();
      }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(begin(cand),end(cand));
        helper(cand,0,target,ans,ds);
        return ans;
    }
};