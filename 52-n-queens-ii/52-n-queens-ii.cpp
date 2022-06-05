class Solution {  
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
public:
    int totalNQueens(int n) {
        vector<vector<string>>ans=solveNQueens(n);
        return ans.size();
    }
};