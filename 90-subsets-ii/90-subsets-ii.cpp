class Solution {
//Brute-Force Approach
//At every index, we make a decision whether to pick or not pick the element at that index. This will help us in generating all possible combinations but does not take care of the duplicates. Hence we will use a set to store all the combinations that will discard the duplicates.
//Time-Complexity:=>O(2^N*k(logX)) ->2^N for generating all the subsets & k*logX for inserting into set of avg size of length k.
//Space Complexity:=>O(2^n * k) 
//     void helper(vector<int>&nums,set<vector<int>>&st,vector<int>ds,int ind){
//       if(ind==nums.size()) {
//         sort(ds.begin(),ds.end());
//         st.insert(ds);
//         return ;
//       }
//       helper(nums,st,ds,ind+1);
//       ds.push_back(nums[ind]);
//       helper(nums,st,ds,ind+1);
//     }
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<vector<int>>ans;
//         set<vector<int>>st;
//         vector<int>ds;
//         helper(nums,st,ds,0);
//         for (auto it = st.begin(); it != st.end(); it++) {
//           ans.push_back( * it);
//         }
//         return ans;
//     }
  void helper(vector<int>&nums,vector<int>&ds,vector<vector<int>>&res,int ind){
      res.push_back(ds);
    for(int i=ind;i<nums.size();i++){
      if(i!=ind && nums[i]==nums[i-1]) continue;//skip duplicates
      ds.push_back(nums[i]);
      helper(nums,ds,res,i+1);
      ds.pop_back();
    }
  }
  public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums){
    sort(begin(nums),end(nums));//sorting will help us to skip duplicates element
    vector<vector<int>>res;
    vector<int>ds;
    helper(nums,ds,res,0);
    return res;
  } 
};