class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        if(n==0) return true;
        int cnt=0;
        for(auto &ch : word)
        {
          if(ch>='A' && ch<='Z') cnt++;
        }
        if(cnt==n || cnt==0) return true;
        if(cnt==1 && (word[0]-'A') >=0 && (word[0]-'A')<26) return true;
        return false;
    }
};