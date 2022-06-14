class Solution {
  public:
  int dp[501][501];
  int helper(string &w1,string &w2,int i,int j){
    if(i==w1.size() && j==w2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i == w1.size()) return dp[i][j]= w2.size() - j;// reached end of word1 -> need to delete remaining characters of word2 to equalize
    if(j == w2.size()) return dp[i][j] =w1.size() - i;// reached end of word2 -> need to delete remaining characters of word1 to equalize
	if(w1[i] == w2[j]) return dp[i][j]= helper(w1, w2, i + 1, j + 1); // the characters  match so we don't need to delete any char simply move to next index of both strings.
    return dp[i][j]=1+min(helper(w1,w2,i+1,j),helper(w1,w2,i,j+1));
  }

    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        memset(dp,-1,sizeof(dp));
        return helper(word1,word2,0,0);
    }
};