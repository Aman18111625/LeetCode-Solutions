class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        int n=t.size(),m=s.size();
        for(int i=0; i<n && j<m;i++)
        {
         if(s[j]==t[i]) j++; 
        }
        return j==m;
    }
};