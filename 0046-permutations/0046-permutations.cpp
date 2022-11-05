class Solution {
  public:
  //Brute-Force Approach->Using Hashmap
  //TC:=>O(N*N!)
  //SC:=>O(N)
  //Run a for loop starting from 0 to n–1. Check if the frequency of i is unmarked, if it is unmarked then it means it has not been picked and then we pick. And make sure it is marked as picked.Call the recursion with the parameters to pick the other elements when we come back from the recursion make sure you throw that element out. And unmark that element in the map.
//   void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
//       if (ds.size() == nums.size()) {
//         ans.push_back(ds);
//         return;
//       }
//       for (int i = 0; i < nums.size(); i++) {
//         if (!freq[i]) {
//           ds.push_back(nums[i]);
//           freq[i] = 1;
//           recurPermute(ds, nums, ans, freq);
//           freq[i] = 0;
//           ds.pop_back();
//         }
//       }
//     }

//     vector < vector < int >> permute(vector < int > & nums) {
//       vector < vector < int >> ans;
//       vector < int > ds;
//       int freq[nums.size()];
//       for (int i = 0; i < nums.size(); i++) freq[i] = 0;
//       recurPermute(ds, nums, ans, freq);
//       return ans;
//     }
  //Optimal Approach ->Using BackTracking
  //TC:=>O(N*N!)
  //SC:=>O(1)
  //Go from 0 to n – 1 and swap. Once the swap has been done call recursion for the next state.After coming back from the recursion make sure you re-swap it because for the next element the swap will not take place.
    void helper(vector<int>&nums,int start,int end,vector<vector<int>>&res){
      if(start==end){
        res.push_back(nums);
        return ;
      }
       for(int i=start;i<end;i++){
         swap(nums[i],nums[start]);
         helper(nums,start+1,end,res);
         swap(nums[i],nums[start]);
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        helper(nums,0,n,res);
        return res;
    }
};