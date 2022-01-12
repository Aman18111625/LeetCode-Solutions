class Solution {
public:
    /*
    int findMinLength(vector<string>&str)
    {
       int min=str[0].length();
        for(int i=1;i<str.size();i++)
        {
          if(str[i].length()<min) min=str[i].length();
        }
        return min;
    }
    string longestCommonPrefix(vector<string>& strs) {
       int minLen=findMinLength(strs);
        string result="";
        char current;
        for(int i=0;i<minLen;i++)
        {
           current=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
            if(strs[j][i]!=current) return result;
            }
            result.push_back(current);
        }
        return result;
    }*/
        string longestCommonPrefix(vector<string>& strs){
        int n =strs.size();
        string ans; 
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[n-1];
        for(int i =0; i< a.size(); i++){
            if(a[i] == b[i]){
                ans += a[i];
            }else break;
        }
        return ans;
    }
};