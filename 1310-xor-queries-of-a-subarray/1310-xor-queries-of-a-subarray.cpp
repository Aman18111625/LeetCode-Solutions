class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
          vector<int>prefix;
          int curr=0;
          for(auto &it : arr)
          {
            curr^=it;
            prefix.push_back(curr);
          }
          vector<int>ans;
          for(auto &it : queries)
          {
            if(it[0]==0) ans.push_back(prefix[it[1]]);
            else ans.push_back(prefix[it[1]]^prefix[it[0]-1]);
          }
       return ans;
    }
};