class Solution {
public:
    //Brute-Force Approach:->Traverse in the whole matrix and find target
    //TC:=>O(N*M)
    //SC:=>O(1)
    //Resule:=>TLE
    // bool searchMatrix(vector<vector<int>>& mat, int target) {
    //   int n=mat.size(),m=mat[0].size();
    //   for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(mat[i][j]==target) return true;
    //     }
    //   }
    //   return false;
    // }
   bool searchMatrix(vector<vector<int>>& mat, int target) {
      int n=mat.size(),m=mat[0].size();
      int i=0,j=m-1;
      while(i<n && j>=0){
       if(mat[i][j]==target) return true;
       else if(mat[i][j]>target) j--;
       else i++;
      }
      return false;
    }
};