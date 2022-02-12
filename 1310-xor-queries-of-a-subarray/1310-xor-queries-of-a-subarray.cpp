class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        /*
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
       return ans;*/
       int n=arr.size();
       int pre[n];
       int Xor=0;
         for(int i=0; i<n; i++)\
         {
             Xor^=arr[i];
             pre[i]=Xor;
         }
         vector<int>ans;
         for(int i=0; i<queries.size(); i++){
            int s = queries[i][0];
            int e = queries[i][1];
            if(s==0) {ans.push_back(pre[e]); continue;}
            else if(s==e) {ans.push_back(arr[e]);}
            else {ans.push_back(pre[e]^pre[s-1]);}
        }
        return ans;
    }
};