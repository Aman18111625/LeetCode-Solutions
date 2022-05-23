class Solution {
public:
  //Brute-Force Approach=>Simply appply recursion =>for every string ->we can include it and not include it.
  //TC:=>exponential SC:=>exponential
  //Optimal Approach->Using DP
  //TC:=>O(L*M*N)
  //SC:=>O(M*N)
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));//store size of largest subset of stsr with maximum limit of 1 and maximum limit of 0.
        for(auto &str : strs){
           int count_0=count(begin(str),end(str),'0');
           int count_1=size(str)-count_0;
           for(int i=m;i>=count_0;i--){
             for(int j=n;j>=count_1;j--){
               //here we have two option for every string of subsets.
               //either we can include it or not it
               //if we include it then 1+optimal soln of remaining 
               dp[i][j]=max(dp[i][j], 1+dp[i-count_0][j-count_1]);
             }
           }
        }
        return dp[m][n];
    }
};