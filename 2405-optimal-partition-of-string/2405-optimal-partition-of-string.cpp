class Solution {
public:
    int partitionString(string s) {
      int n=s.size();
      int res=0,last=0;
      vector<int>pos(26,0);
      for(int i=0;i<n;i++){
        if(pos[s[i]-'a']>=last) {
          res++;
          last=i+1;
        }
        pos[s[i]-'a']=i+1;
      }
      return res;
    }
};
  