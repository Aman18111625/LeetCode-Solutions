class Solution {
  /*
  Rules of Sudoku solver:-
  1.Each of the digits 1-9 must occur exactly once in each row.
  2.Each of the digits 1-9 must occur exactly once in each column.
  3.Each of the digits 1-9 must occur exactly once in each of the 9,3x3 subboxes of the grid.
  */
  //According to Question->we have to fill all the empty cells->So by checking all the possible way we can get desired output.
  //Step1->whenver we get a empty cell -> run a for from '1' to '9'  and check which one is valid .For checking Validity we have a another function isValid ->if it's not valid then move to next number.
  //Checking validity=>run a for loop from 0 to 8 and check this 
  //1. board[i][col]!=ch ->for row
  //2. board[row][j]!=ch ->for col
  //3. board[3*(row/3)+i/3][3*(col/3)+i%3]!=ch ->for 3*3 sub-matrix.
  
  //Time-Complexity:=>O(9^(n^2))
  //Space-Complexity:=>O(1)
  bool isValid(vector<vector<char>>&board,int row,int col,char c){
      for(int i=0;i<9;i++){
       if(board[i][col]==c) return false;
       if(board[row][i]==c) return false;
       if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
      }
      return true;
  }
public:
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);   
    }
  bool solve(vector<vector<char>>&board){
    int n=9;
     for(int i=0;i<9;i++){
       for(int j=0;j<9;j++){
        if(board[i][j]=='.'){
         for(char c='1';c<='9';c++) {
           if(isValid(board,i,j,c)){
             board[i][j]=c;
             if(solve(board)==true) return true;
             else board[i][j]='.';
           } 
         } 
        return false;    
        }  
      }
     }
  return true;
 }
    
};