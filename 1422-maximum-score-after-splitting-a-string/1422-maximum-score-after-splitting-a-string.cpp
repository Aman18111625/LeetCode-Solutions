class Solution {
public:
    int maxScore(string s) {
        int ans=0,cnt0=0,cnt1=0;
        for(auto it: s) if(it=='1') cnt1++;
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0') cnt0++;
            else cnt1--;
            ans=max(ans,cnt0+cnt1);
        }
        return ans;
    }
};