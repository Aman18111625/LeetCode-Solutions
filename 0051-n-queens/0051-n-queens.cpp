class Solution {
public:
  /*Rules for N-Queen in ChessBoard
   1.Each row & Each Column should have 1 Queen
   2.No two Queen's attack on each -other/
   A Queen can attack in all possible 8-directions
  */
  
  //Brute-Approach->check for all possible  && find right arrangement of N-Queens in n*n chessBoard
  //TC:=>O(N*N!) Exponential in nature, since we are trying out all ways. 
  //SC:=>O(N^2)(stack-space)
//   bool isSafe(int row,int col,vector<string>& board,int n){
//         int dupRow=row;
//         int dupCol=col;
           //Upper diagonal
//         while(row>=0 and col>=0)  {
//             if(board[row][col]=='Q') return false;
//             row--;
//             col--;
//         }
//         col=dupCol;
          //left Row 
//         while(col>=0){
//             if(board[row][col]=='Q') return false;
//             col--;
//         }
           //lower diagonal
//         col=dupCol;
//         row=dupRow;
//         while(row<n and col>=0){
//             if(board[row][col]=='Q') return false;
//             row++;
//             col--;
//         }
//         return true;
//     }
    
//     void solve(int col,vector<string>& board,vector<vector<string>>& res,int n){
//      if(col==n){//no queen's left
//          res.push_back(board);
//          return ;
//      }
        
//       for(int row=0;row<n;row++){
//         if(isSafe(row,col,board,n)){
//               board[row][col]='Q';//assign 'Q' and call for next 
//               solve(col+1,board,res,n);
//               board[row][col]='.';//backtrack so that we can explore other possible arrangements
//         }
//       }
//     }
  
//     vector<vector<string>>solveNQueens(int n){
//         vector<vector<string>>res;
//         vector<string>board(n);//create board
//         string s(n,'.');//initial set as '.'
//         for(int i=0;i<n;i++)
//              board[i]=s;
        
//         solve(0,board,res,n);
//         return res;
//     }   
  //Optimized Approach->Using Hashing
  //TC:=>O(N*N!)
  //SC:->O(N+(2N)+(2N))=>O(N)
  //Thought Process:=>In the previous issafe function, we need o(N) for a row, o(N) for the column, and o(N) for diagonal. Here, we will use hashing to maintain a list to check whether that position can be the right one or not.
void solve(int col,vector<string>& board,vector<vector<string>>& res,vector<int>& leftRow,vector<int>& upperDiagonal,vector<int>& lowerDiagonal,int n){
        if(col==n){//no Queen's are left
            res.push_back(board);
            return ;
        }
    for(int row=0;row<n;row++){
      if(leftRow[row]==0 and lowerDiagonal[row+col]==0 and upperDiagonal[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                solve(col+1,board,res,leftRow,upperDiagonal,lowerDiagonal,n);
               //back-track
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }
  vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
             board[i]=s;
        
        vector<int>leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        solve(0,board,res,leftRow,upperDiagonal,lowerDiagonal,n);
        return res;
    }
};

    