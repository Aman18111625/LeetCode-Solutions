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
  //Recursive+Meoization
  //TC:=>O(N^2)
  //SC:=>O(N)+O(N)(stack-Space)
//    bool canBrk(int start, string& s, unordered_set<string>& dict,vector<int>&dp){
//     int n = s.size();
//     if(start == n) return 1;
//     if(dp[start]!=-1) return dp[start];
//     string sub;
//     for(int i = start; i<n; i++)
//         if(dict.count(sub+=s[i]) && canBrk(i+1,s,dict,dp)) return dp[start]=1;
//     return dp[start]=0;
//   }

//      bool wordBreak(string s, vector<string>& wordDict) {
//          unordered_set<string>dict;
//          //insert all the dictionary words into set
//          for(string& word: wordDict) dict.insert(word);
//          vector<int>dp(s.size(),-1);
//          return canBrk(0,s,dict,dp);    
//     }
  
  //Top-Down Appraoch
  //TC:=>O(N^2)
  //SC:=>O(N)
   bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        int dp[n+1];
        memset(dp,0,sizeof dp);
        dp[n]=1;
        
        unordered_set<string>dict; //to store all the words of dictionary into set
        for(string& word : wordDict)
            dict.insert(word);
        
        for(int i=n-1;i>=0;i--)
        {
          string check;
         for(int j=i;j<n;j++)
         {
             check.push_back(s[j]);
             if(dict.find(check)!=dict.end())
             {
               if(dp[j+1])dp[i]=1;
             }
         }  
        }
        return dp[0];
   }  
};