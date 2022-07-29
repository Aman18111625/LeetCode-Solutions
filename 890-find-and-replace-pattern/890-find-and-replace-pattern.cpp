class Solution {
public:
      bool wordPattern(string pat, string s) {
        unordered_map<char,char>mpp;
        set<char>st;
        for(int i=0;i<pat.size();i++){
            if(mpp.find(pat[i])==mpp.end())
            {
                if(st.count(s[i])>=1) return false;
                mpp[pat[i]]=s[i];
                st.insert(s[i]);
                
            }else
            {
                if(mpp[pat[i]]!=s[i]) return false;
            }
        }
        return true;
    }
  
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto &word : words){
          if(word.size()!=pattern.size()) continue;
          else if(wordPattern(pattern,word)){
            ans.push_back(word);
          }
        }
      return ans;
    }
};