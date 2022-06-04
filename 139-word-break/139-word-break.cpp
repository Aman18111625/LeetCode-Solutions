class Solution {
public:
  //Brute-Force Approach->Using Recursion
  //Time-Complexity:=>O(2^N)
  //Space-Complexity:=>O(N)
  //We're checking for all the possible sub-string 
//  bool canBrk(int start, string& s, unordered_set<string>& dict){
//     int n = s.size();
//     if(start == n) return 1;
//     string sub;
//     for(int i = start; i<n; i++)
//         if(dict.count(sub+=s[i]) && canBrk(i+1,s,dict)) return 1;
//     return 0;
// }

//      bool wordBreak(string s, vector<string>& wordDict) {
//          unordered_set<string>dict;
//          for(string& word: wordDict) dict.insert(word);
//         return canBrk(0,s,dict);    
//     }
  //Optimal Solution->Using Dynamic Programming
  //TC:=>O(N^2)
  //SC:=>O(N)
   bool canBrk(int start, string& s, unordered_set<string>& dict,vector<int>&dp){
    int n = s.size();
    if(start == n) return 1;
    if(dp[start]!=-1) return dp[start];
    string sub;
    for(int i = start; i<n; i++)
        if(dict.count(sub+=s[i]) && canBrk(i+1,s,dict,dp)) return dp[start]=1;
    return dp[start]=0;
  }

     bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string>dict;
         //insert all the dictionary words into set
         for(string& word: wordDict) dict.insert(word);
         vector<int>dp(s.size(),-1);
         return canBrk(0,s,dict,dp);    
    }
};