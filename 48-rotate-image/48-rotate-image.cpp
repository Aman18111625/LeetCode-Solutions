class Solution {
public:
  //Approach-1 Brute Force
  //Time-Complexity:=>O(N^2) Space-Complexity:=>O(N^2)
    void rotate(vector<vector<int>>& mat) {
         int n=mat.size();
         vector<vector<int>>ans(n,vector<int>(n,0));
         for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
             ans[j][n-i-1]=mat[i][j];
           }
         }
      
         for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
             mat[i][j]=ans[i][j];
           }
         }
      
    }
};