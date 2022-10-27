#define p pair<int,int>
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<p>temp1,temp2;
        int n=img1.size(),m=img2.size();
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(img1[i][j]==1)
              temp1.push_back({i,j});
            
            if(img2[i][j]==1)
              temp2.push_back({i,j}); 
          }
        }
          int ans=0;
          map<p,int>mp;
          for(auto i: temp1){
            for(auto j: temp2){
              int x=i.first-j.first;
              int y=i.second-j.second;
              mp[{x,y}]++;
              ans=max(ans,mp[{x,y}]);
            }
          }
        return ans;
    }
};
      
