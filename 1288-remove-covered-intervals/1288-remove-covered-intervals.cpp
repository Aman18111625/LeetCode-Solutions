class Solution {
  bool static cmp(vector<int>&a,vector<int>&b){
    if(a[0]>b[0]) return 0;
    else if(a[1]>b[1]) return 1;
    return 1;
  }
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
         sort(inter.begin(),inter.end(),cmp);
         auto temp=inter[0];
         int n=inter.size();
         int cnt=n;
        for(int i=1;i<n;i++){
          if(inter[i][1]<=temp[1]){
           cnt--;
          }else{
            temp=inter[i];
          }
        }
      return cnt;
    }
};

    