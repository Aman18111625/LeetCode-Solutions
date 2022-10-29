class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>ans;
        int n=plantTime.size();
        for(int i=0;i<n;i++){
          ans.push_back({growTime[i],plantTime[i]});
        }
        
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        int res=INT_MIN,prev=0;
        for(int i=0;i<n;i++){
          int growT=ans[i].first;
          int plantT=ans[i].second;
          prev+=plantT;
          int bloomTime=prev+growT+1;
          res=max(res,bloomTime);
        }
        return res-1;
    }
};
