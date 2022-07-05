class Solution {
public:
    //Approach-1 : Using Sorting
    //TC:=>O(M*N)+O(NLOGN)
    //SC:=>O(N)
    // vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    //     vector<pair<int,int>>vec;//to store count of 1 in corresponding row
    //     vector<int>ans;
    //     for(int i=0;i<mat.size();i++){
    //       int cnt=0;
    //       for(int j=0;j<mat[0].size();j++){
    //         if(mat[i][j]==1) cnt++;
    //         else break;
    //       }
    //       vec.push_back({cnt,i});
    //     }
    //     sort(vec.begin(),vec.end());//sort in increasing order of count of 1
    //     for(int i=0;i<k;i++){
    //       ans.push_back(vec[i].second);//include k in our answer
    //     }
    //   return ans;
    // }
  
  //Approach-2 : Using PriorityQueue
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;//to store count of 1 in corresponding row
        vector<int>ans;
        for(int i=0;i<mat.size();i++){
          int cnt=0;
          for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==1) cnt++;
            else break;
          }
          pq.push({cnt,i});
          if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
          ans.push_back(pq.top().second);
          pq.pop();
        }
        reverse(ans.begin(),ans.end());//important step otherwise we'll get WA
      return ans;
    }
};