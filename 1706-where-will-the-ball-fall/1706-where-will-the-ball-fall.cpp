class Solution {
public:
    // ThoughtProcess/Intution :- we can simulate the movement of each ball.If a ball is stuck at some point, then it would be -1 otherwise, get the final destination column.
   //step-1 Iterate each column 
   //step-2 Iterate each row
   //step-3 find next_col ->the next_col woule ne the curr_col+ the value of the curr_cell
   //step-4 we need to check if the ball gets stuck at the same column and there are three cases
//Case-1.the ball on the leftmost column is moving to the left hence,we check next_col<0
//Case-2.the ball on the rightmost column is moving to the right hence,we check next_col>=n
//Case-3. the ball is stuck at a V shape position
//e.g. ball 2 and ball 3 in column 2 and column 3 in row 0
//hence, we check if the if grid[cur_row][cur_col] is different than grid[cur_row][next_col]
    vector<int> findBall(vector<vector<int>>& grid) {
      int m=grid.size(),n=grid[0].size();
      vector<int>ans;
      //step-1
      for(int j=0;j<n;j++){
        int curr_col=j;
        //step-2
        for(int i=0;i<m;i++){
          //step-3
          int next_col=curr_col+grid[i][curr_col];
          //case checking
          if(next_col<0 or next_col>=n or (grid[i][curr_col]^grid[i][next_col])){
            curr_col=-1;
            break;
          }
          curr_col=next_col;
        }
        ans.push_back(curr_col);
      }
      return ans;
    }
};

