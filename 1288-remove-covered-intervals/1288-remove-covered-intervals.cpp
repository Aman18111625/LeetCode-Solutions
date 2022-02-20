class Solution {
  /*
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
    }*/
  public:
   int removeCoveredIntervals(vector<vector<int>>& intervals) {
        map<int,int>mpp;//we're ordered map because we need interval in sequence
        for(auto &i: intervals) if(i[1]>mpp[i[0]]) mpp[i[0]]=i[1];
        int x = mpp.begin()->first, y = mpp.begin()->second; //assign x as key and y as value
        int cnt = 1; 
        for(auto &it: mpp){
            if(x<=it.first and y>=it.second)continue; 
            else cnt++, x=it.first,y=it.second; 
        }
        return cnt;
    }
};

    