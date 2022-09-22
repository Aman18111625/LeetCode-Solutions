class Solution {
public:
    string reverseWords(string s) {
      vector<string>temp;
      string curr="";
      for(auto ch: s){
        if(ch==' ') {
          reverse(curr.begin(),curr.end());
          temp.push_back(curr);
          curr="";
        }
        else curr+=ch;
      }
      reverse(curr.begin(),curr.end());
      temp.push_back(curr);
      string ans="";
      for(int i=0;i<temp.size();i++){
        ans+=temp[i];
        if(i!=temp.size()-1) ans+=" ";
      }
      return ans;
    }
};