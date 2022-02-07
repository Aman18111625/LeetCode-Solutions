class Solution {
public:
  /* TC:=>O(NLogN) SC:=>O(1)
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
    }*/
  char findTheDifference(string s, string t) {
       int freq[26]= {0};
        for(auto &it : s)
            freq[it-'a']--;
        
        for(auto &it : t)
            freq[it-'a']++;
        
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i]) return i+'a';
        }
        return 'b';
    }
};