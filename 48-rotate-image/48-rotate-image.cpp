class Solution {
public:
  //Approach-1 Brute Force
  //Time-Complexity:=>O(N^2) Space-Complexity:=>O(N^2)
  //create a dummy matrix of size n*n ,now put first row of matrix into last column..2nd row->2nd last column and so on...
//     void rotate(vector<vector<int>>& mat) {
//          int n=mat.size();
//          vector<vector<int>>ans(n,vector<int>(n,0));
//          for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//              ans[j][n-i-1]=mat[i][j];
//            }
//          }
      
//          for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//              mat[i][j]=ans[i][j];
//            }
//          }
      
//     }
  //Approach-2 Optimized Approach
  //Intuition:=> By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, so that’s why we transpose the matrix and then reverse each row
  //step-1 Transpose of given matrix so that row will become column and hence column will become row
  //Step-2 Now reverse each row
  //Time-Complexity=>O(N^2)
  //Space-Complexity=>O(1)
   void rotate(vector<vector<int>>& mat) {
         int n=mat.size();
         for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
              swap(mat[i][j],mat[j][i]);
           }
         }
      
         for(int i=0;i<n;i++){
           reverse(mat[i].begin(),mat[i].end());
         }
      
    }
};