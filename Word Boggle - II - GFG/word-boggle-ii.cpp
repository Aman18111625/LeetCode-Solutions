// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
   bool dfs(int i,int j,int n, int m ,string word ,vector<vector<char> >& dict){
        if(word.size() == 0) return true;
        if(i<0 or i>=n or j<0 or j>=m or dict[i][j]!=word[0]) return false;
        char org = dict[i][j];
        dict[i][j]='#';
        string check = word.substr(1);

        bool ans = dfs(i+1 ,j , n , m , check , dict);
        ans |= dfs(i-1 ,j , n , m , check , dict);
        ans |= dfs(i ,j-1 , n , m , check , dict);
        ans |= dfs(i ,j+1 , n , m , check , dict);
        ans |= dfs(i+1 ,j+1 , n , m , check , dict);
        ans |= dfs(i+1 ,j-1 , n , m , check , dict);
        ans |= dfs(i-1 ,j+1 , n , m , check , dict);
        ans |= dfs(i-1 ,j-1 , n , m , check , dict);
        
        dict[i][j] = org;
        return ans;
    }
   
    bool solve(string word ,vector<vector<char> >& dict){
        int n = dict.size(), m = dict[0].size();
        for(int i=0 ;i<n;i++)
        for(int j=0 ;j<m;j++){
            if(dfs(i,j,n,m,word,dict))
                return true;
        }
        return false;
    }
  
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	   vector<string>ans;
	    unordered_set<string>set;
	    for(auto word :dictionary ){
	        if(solve(word,board)){
	            if(set.find(word)==set.end())
	                ans.push_back(word);
	                set.insert(word);
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