class Solution {
public:
  //Brute-Force
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
};
