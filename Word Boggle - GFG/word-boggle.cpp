// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
     vector<int>dir_x={0,0,-1,-1,-1,1,1,1};
     vector<int>dir_y={1,-1,0,-1,1,0,-1,1};
     
     bool dfs(vector<vector<char>>&board,string word,int i,int j,int n,int m,int len){
         if(len==word.size()) return true;
         char c=board[i][j];
         board[i][j]='0';
         bool res=false;
         for(int dir=0;dir<8;dir++){
             int x=i+dir_x[dir];
             int y=j+dir_y[dir];
             if(x>=0 && x<n && y>=0 && y<m && board[x][y]==word[len]){
                 res|=dfs(board,word,x,y,n,m,len+1);
             }
         }
         board[i][j]=c;
         return res;
     }
     
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string>ans;
	    int n=board.size(),m=board[0].size();
	    for(auto word : dictionary){
	        bool flag=false;
	        for(int i=0;i<n && !flag;i++ ){
	            for(int j=0;j<m && !flag;j++){
	                if(word[0]==board[i][j]  && dfs(board, word, i, j, n, m, 1)){
	                    ans.push_back(word);
	                    flag=true;
	                }
	            }
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends