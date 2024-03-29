//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
 
        
    bool isSafe(int i,int j,int n,int m,vector<vector<int>>&vis){
        if(i>=0 && i<n && j>=0 && j<m && !vis[i][j]) return true;
        return false;
    }
    
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&mat,int dr[],int dc[]){
        vis[i][j]=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int dir=0;dir<4;dir++){
            int nrow=dr[dir]+i;
            int ncol=dc[dir]+j;
            if(isSafe(nrow,ncol,n,m,vis) && mat[nrow][ncol]=='O'){
               dfs(nrow,ncol,vis,mat,dr,dc); 
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        //traverse the first row & last column
            for(int j=0;j<m;j++){
                //first row
                if(!vis[0][j] && mat[0][j]=='O'){
                    dfs(0,j,vis,mat,dr,dc);
                }
                //last row
                if(!vis[n-1][j] && mat[n-1][j]=='O'){
                    dfs(n-1,j,vis,mat,dr,dc);
                }
            }
            for(int i=0;i<n;i++){
                //first col
                if(!vis[i][0] && mat[i][0]=='O'){
                    dfs(i,0,vis,mat,dr,dc);
                }
                //last col
                if(!vis[i][m-1] && mat[i][m-1]=='O' ){
                    dfs(i,m-1,vis,mat,dr,dc);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(!vis[i][j] && mat[i][j]=='O'){
                        mat[i][j]='X';
                    }
                }
            }
            return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends