class Solution {
   /*
   bool isSafe(int row,int col,vector<string>& board,int n)
    {
        int dupRow=row;
        int dupCol=col;
        while(row>=0 and col>=0)  
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        col=dupCol;
        row=dupRow;
        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }
        col=dupCol;
        row=dupRow;
        while(row<n and col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int col,vector<string>& board,vector<vector<string>>& res,int n)
    {
     if(col==n)
     {
         res.push_back(board);
         return ;
     }
        for(int row=0;row<n;row++)
        {
          if(isSafe(row,col,board,n))
          {
              board[row][col]='Q';
              solve(col+1,board,res,n);
              board[row][col]='.';
          }
        }
    }
    */
void solve(int col,vector<string>& board,vector<vector<string>>& res,vector<int>& leftRow,vector<int>& upperDiagonal,vector<int>& lowerDiagonal,int n)
    {
        if(col==n)
        {
            res.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++)
        {
         if(leftRow[row]==0 and lowerDiagonal[row+col]==0 and upperDiagonal[n-1+col-row]==0) 
            {
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                solve(col+1,board,res,leftRow,upperDiagonal,lowerDiagonal,n);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }
public:
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