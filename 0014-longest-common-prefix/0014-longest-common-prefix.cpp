class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(begin(strs),end(strs));
        string a=strs[0];
        string b=strs[strs.size()-1];
        string ans="";
        int i=0;
        while(i<a.size() && a[i]==b[i]){
          ans+=a[i];
          i++;
        }
        return ans;
    }
};