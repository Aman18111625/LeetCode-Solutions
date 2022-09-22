class Solution {
public:
    //Brute-Force:=>Using Extra space
    // string reverseWords(string s) {
    //   vector<string>temp;
    //   string curr="";
    //   for(auto ch: s){
    //     if(ch==' ') {
    //       reverse(curr.begin(),curr.end());
    //       temp.push_back(curr);
    //       curr="";
    //     }
    //     else curr+=ch;
    //   }
    //   reverse(curr.begin(),curr.end());
    //   temp.push_back(curr);
    //   string ans="";
    //   for(int i=0;i<temp.size();i++){
    //     ans+=temp[i];
    //     if(i!=temp.size()-1) ans+=" ";
    //   }
    //   return ans;
    // }
   
  //Optimized Approach:=>Without extra space
    string reverseWords(string& s){
        int i = 0;
        for (int j=0;j<s.size();++j) {
            if (s[j]==' ') {
                reverse(s.begin()+i,s.begin()+j);
                i=j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};