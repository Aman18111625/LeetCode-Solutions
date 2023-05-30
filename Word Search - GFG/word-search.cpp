//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

    bool helper(vector<vector<char>>&board,string &word,int i,int j,int n,int m,int len){
       if(i<0 or i>=n or j<0 or j>=m or board[i][j]!=word[len]) return false;
       if(len==word.size()-1) return true;
       char temp=board[i][j];
       board[i][j]='.';
       bool res=helper(board,word,i,j+1,n,m,len+1);
       res|=helper(board,word,i,j-1,n,m,len+1);
       res|=helper(board,word,i+1,j,n,m,len+1);
       res|=helper(board,word,i-1,j,n,m,len+1);
       board[i][j]=temp;
       return res;
   }
   public:
   bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(helper(board,word,i,j,n,m,0))
                     return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends