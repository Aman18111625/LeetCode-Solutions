class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>vec;//to store count of 1 in corresponding row
        vector<int>ans;
        for(int i=0;i<mat.size();i++){
          int cnt=0;
          for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==1) cnt++;
            else break;
          }
          vec.push_back({cnt,i});
        }
        sort(vec.begin(),vec.end());//sort in increasing order of count of 1
        for(int i=0;i<k;i++){
          ans.push_back(vec[i].second);//include k in our answer
        }
      return ans;
    }
};