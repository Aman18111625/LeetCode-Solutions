class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        if(s1.size()!=s2.size()) return false;
        int idx1=-1,idx2=-1;
        int n=s1.size();
        for(int i=0;i<n;i++){
          if(s1[i]!=s2[i] && idx1==-1) 
             idx1=i;
          else if(s1[i]!=s2[i] && idx2==-1) 
             idx2=i;
          else if(s1[i]!=s2[i] && idx1!=-1 && idx2!=-1) 
             return false;
        }
      if(idx1!=-1 && idx2!=-1) swap(s2[idx1],s2[idx2]);
      return s1==s2;
    }
};
   