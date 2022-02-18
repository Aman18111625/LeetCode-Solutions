class Solution {
bool helper(vector<vector<char>>& board,int i,int j,string& word,int idx)
{
if(idx==word.size()) return true; 
if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]=='.' or board[i][j]!=word[idx]) return false;  //check for boundaries or already visited or char is not equal to word then return false
       char c = board[i][j]; 
      board[i][j] = '.';//mark as visited
//call for all 4-direction if got true from any one of them it means word exists in the grid
        bool res = helper(board, i+1, j, word, idx+1) ||
                   helper(board, i-1, j, word, idx+1) ||
                   helper(board, i, j+1, word, idx+1) ||
                   helper(board, i, j-1, word, idx+1);
          board[i][j] = c;//backtrack
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int m=board.size();//no of rows
        int n=board[0].size();//no of columns
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              if(helper(board,i,j,word,0)) return true; //check for every i,j if got true from helper it means word is exists in the grid so simply return true
          }
      }
        return false;//after checking in grid we didn't find word so return false;
    }
};