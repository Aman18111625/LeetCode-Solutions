class Solution {
    void helper(vector<int>&nums,set<vector<int>>&st,vector<int>ds,int ind){
      if(ind==nums.size()) {
        sort(ds.begin(),ds.end());
        st.insert(ds);
        return ;
      }
      helper(nums,st,ds,ind+1);
      ds.push_back(nums[ind]);
      helper(nums,st,ds,ind+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>ds;
        helper(nums,st,ds,0);
        for (auto it = st.begin(); it != st.end(); it++) {
          ans.push_back( * it);
        }
        return ans;
    }
};