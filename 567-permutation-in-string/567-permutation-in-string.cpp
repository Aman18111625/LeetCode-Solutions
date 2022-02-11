class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      unordered_map<char,int>mpp;
      for(auto &ch : s1) mpp[ch]++;
      int win=s1.size();//size of window
      int cnt=mpp.size();//no of distinct char in s1
      int i=0,j=0,n=s2.size();
      while(j<n)
      {
          if(mpp.find(s2[j])!=mpp.end())
          {
            mpp[s2[j]]--;
            if(mpp[s2[j]]==0) cnt--;
          }
          if(j-i+1<win)j++;
          else if(j-i+1==win)
          {
             if(cnt==0) return true;
             if(mpp.find(s2[i])!=mpp.end())
             {
               mpp[s2[i]]++;
               if(mpp[s2[i]]==1) cnt++;
             }
            i++;j++;
          }
       }
      return false;
    }
};
/*  string m1(26,0), m2(26,0);
        for( auto ch : s1) m1[ch-'a']++;        
        for( int r = 0 ; r < s2.size() ; r++){
            m2[s2[r]-'a']++;
            if( r >= s1.size() ) m2[s2[r-s1.size()] - 'a']--;
            if( m2 == m1) return true;
        }        
        return false;
        */
 
  