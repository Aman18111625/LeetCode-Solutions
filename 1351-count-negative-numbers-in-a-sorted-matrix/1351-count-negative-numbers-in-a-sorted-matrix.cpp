class Solution {
public:
      //Naive Approach->Simple iterate throught whole matrix and count negative numbers
      //TC:=>O(M*N)
      //SC:=>O(1)
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]<0) cnt++;
          }
        }
        return cnt;
    }
};