class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s=="") return t[0];
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
      int i=0,j=0,n=s.size(),m=t.size();
      while(i<n && j<m) 
      {
        if(s[i]==t[j]) i++,j++;
        else break;
      }
        return t[j];
    }
};