class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
         sort(p.begin(),p.end());//sort according to start time
        int n=p.size(),lastEnd=p[0][1];
        int ans=0;
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
        ans++;//doing this because we're unable to check for last interval
        return ans;
    }
};