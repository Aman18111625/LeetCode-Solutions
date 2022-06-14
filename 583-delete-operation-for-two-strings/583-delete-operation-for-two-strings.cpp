class Solution {
  public:
//Recursive+Meoization
//TC:=>O(N*M)
//SC:=>O(N*M)+O(max(N,M))(stack-space)
//   int dp[501][501];
//   int helper(string &w1,string &w2,int i,int j){
//     if(i==w1.size() && j==w2.size()) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(i == w1.size()) return dp[i][j]= w2.size() - j;// reached end of word1 -> need to delete remaining characters of word2 to equalize
//     if(j == w2.size()) return dp[i][j] =w1.size() - i;// reached end of word2 -> need to delete remaining characters of word1 to equalize
// 	if(w1[i] == w2[j]) return dp[i][j]= helper(w1, w2, i + 1, j + 1); // the characters  match so we don't need to delete any char simply move to next index of both strings.
//     return dp[i][j]=1+min(helper(w1,w2,i+1,j),helper(w1,w2,i,j+1));
//   }

//     int minDistance(string word1, string word2) {
//         int n=word1.size(),m=word2.size();
//         memset(dp,-1,sizeof(dp));
//         return helper(word1,word2,0,0);
//     }
  
  //Tabulation or Top-Down Approach
  //TC:=>O(N*M)
  //SC:=>O(N*M)
//   int minDistance(string& word1, string& word2) {  
//    int n=word1.size(),m=word2.size();
// 	 vector<vector<int> >dp(n+1, vector<int>(m+1));
// 	 for(int i = 0; i <=n; i++){
// 		for(int j = 0; j <= m; j++){ 
// 			if(!i || !j) 
//       dp[i][j] = i + j;//if one word == "",all other char of other word need to be deleted
// //if char match?dont delete:1 delete+min to equalize after delete of (word1[i], word2[j])
// 			else
//         dp[i][j]=word1[i-1] == word2[j-1]?dp[i-1][j-1]:1+min(dp[i-1][j], dp[i][j-1]);
//     }
//    }
// 	 return dp[n][m];
// }
  //Space-Optimization
  //TC:=>O(N*M)
  //SC:=>O(M)
  int minDistance(string& word1, string& word2) {  
     int n=word1.size(),m=word2.size();
     vector<int>prev(m+1,0),curr(m+1,0);
	  for(int i = 0; i <=n; i++) {
	  	for(int j = 0; j <= m; j++){
       if(i==0 || j==0) curr[j] =0;
		 	 else curr[j] =(word1[i-1] == word2[j-1])? 1+prev[j-1] :  max(prev[j], curr[j-1]);
     }
		prev=curr;
   }
  //Track how many characters are extra in both strings. Extra means difference between string length and lcs length 
	return n+m-2*prev[m];
}
};

           
      
 