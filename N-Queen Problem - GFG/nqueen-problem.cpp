// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    bool isSafe(int row,int col,vector<string>board,int n){
        int dupRow=row,dupCol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--,col--;
        }
        row=dupRow,col=dupCol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col=dupCol;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++,col--;
        }
        return true;
    }
    
    void solve(int col,int n,vector<vector<int>>&ans,vector<string>&board,vector<int>&temp){
        if(col==n){
          ans.push_back(temp);
          return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                temp[col]=row+1;
                solve(col+1,n,ans,board,temp);
                //backtrack
                board[row][col]='.';
                temp[col]=0;
            }
        }
    }
    
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        vector<int>temp(n,0);
        solve(0,n,ans,board,temp);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends