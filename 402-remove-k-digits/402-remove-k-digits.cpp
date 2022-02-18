class Solution {
public:
    string removeKdigits(string num, int k) {
      int n=num.size();
      if(n==k) return "0";//we have to remove all the digits so answer will be "0"
      string ans="";
      ans+=num[0];
      for(int i=1;i<n;i++){
        while(i<n && num[i]<ans.back() && k){
          ans.pop_back();
          k--;
        }
        if(!ans.empty() || num[i]!='0')ans+=num[i];
      }
      while(!ans.empty() && k){
        ans.pop_back();
        k--;
      }
      return ans.empty()?"0":ans;
    }
};