class Solution {
void helper(string &s,string curr,unordered_set<string>&dict,vector<string>&res,int start){
      int n=s.size();
      if(start==n){//reached at the end
        curr.pop_back();//erase trolling space
        res.push_back(curr);
        return ;
      }
      string sub;
      for(int i=start;i<n;i++){
          sub+=s[i];
          if(dict.count(sub)){
            helper(s,curr+sub+" ",dict,res,i+1);
          }
      }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        unordered_set<string>dict;
        for(auto word : wordDict){
          dict.insert(word);
        }
        string curr="";
        helper(s,curr,dict,res,0);
        return res;
    }
};