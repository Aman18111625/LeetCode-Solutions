class Solution {
public:
  //Brute-Force
  //Time-Complexity:=>O((N*M)(N+M))
  //Space-Complexity:=>O(1)
  /*
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(mat[i][j]==0){
               int row=i-1;
               while(row>=0){
                 if(mat[row][j]!=0) mat[row][j]=1e9;
                 row--;
               }
               row=i+1;
               while(row<n){
                 if(mat[row][j]!=0) mat[row][j]=1e9;
                 row++;
               }
               int col=j-1;
               while(col>=0){
                 if(mat[i][col]!=0)  mat[i][col]=1e9;
                 col--;
               }
               col=j+1;
               while(col<m){
                 if(mat[i][col]!=0) mat[i][col]=1e9;
                 col++;
               }
            }
          }
        }
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(mat[i][j]==1e9) mat[i][j]=0;
          }
        }
    }*/
    //Better Approach
    //Time-Complexity:->O(N*M)
    //Space-Complexity:->O(N)+O(M)
  /*
    void setZeroes(vector<vector<int>>& mat){
      int n=mat.size();
      int m=mat[0].size();
      vector<int>row(n,-1),col(m,-1);
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(mat[i][j]==0){
            row[i]=0;
            col[j]=0;
          }
        }
      }
       
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(row[i]==0 or col[j]==0) mat[i][j]=0;
        }
      }
    }
    */
  //Optimized Approach
  //Time-Complexity:->O(N*M)
  //SPace-Compleixty:->O(1)
  void setZeroes(vector<vector<int>>& mat){
    int n=mat.size(),m=mat[0].size();
    int col0=1;
    for(int i=0;i<n;i++){
      if(mat[i][0]==0) col0=0;
      for(int j=1;j<m;j++){
        if(mat[i][j]==0){
          mat[i][0]=0;
          mat[0][j]=0;
        }
      }
    }
    for(int i=n-1;i>=0;i--){
      for(int j=m-1;j>=1;j--){
        if(mat[i][0]==0 or mat[0][j]==0){
          mat[i][j]=0;
        }
      }
      if(col0==0) mat[i][0]=0; 
    }
  }
};
