class Solution {
public:
    /*
    int findMinArrowShots(vector<vector<int>>& p) {
         sort(p.begin(),p.end());//sort according to start time
        int n=p.size(),lastEnd=p[0][1];
        int ans=1;//we need to atleast one arrow to burst first ballons
        for(auto &curr : p)
        {
        if(lastEnd>=curr[0])//if interval is intersecting then update lastEnd with minimum of them
            {
                lastEnd=min(lastEnd,curr[1]);
            }else//now bullon can burst so increase answer by 1 and update lastEnd with curr
            {
                ans++;
                lastEnd=curr[1];
            }
        }
        return ans;
    }*/
     int findMinArrowShots(vector<vector<int>>& p) {
         //sort according to end time
        sort(p.begin(),p.end(),[](vector<int>&a,vector<int>&b){
            if(a[1]==b[1])return a[0]<b[0];
            return a[1]<b[1];
        });
        int ans=1,n=p.size();
        int prev=p[0][1];
        for(int i=1;i<n;i++){
            if(prev>=p[i][0])continue;
            ans++;
            prev=p[i][1];
        }
        return ans;
    }
};