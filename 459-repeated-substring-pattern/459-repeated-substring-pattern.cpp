class Solution {
public:
    /*
    bool repeatedSubstringPattern(string s) {
        string rot=s+s;
        rot.pop_back();
        rot=rot.substr(1);
        if(rot.find(s)!=string::npos) return true;
        return false;
    }*/
     bool repeatedSubstringPattern(string s) {
        int n=s.length();
        vector<int> lps(n,0);
        int i=1, j=0;
        for(i=1;i<n;)
        {
            if(s[i]==s[j])
            {
                lps[i++]=++j;
            }
            else
            {
                if(j)
                {
                    j=lps[j-1];
                }
                else
                {
                    lps[i++]=0;
                }
            }
        }
        return lps[n-1] && (lps[n-1]%(n-lps[n-1])==0);
    }
};