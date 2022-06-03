class Solution {
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