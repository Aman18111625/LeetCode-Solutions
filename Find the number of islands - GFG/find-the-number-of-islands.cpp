// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
    // void dfs(vector<vector<char>>&grid,int i,int j,int &n,int &m){
    //     if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!='1') return ;//boundary cases
    //     //mark as visited
    //     grid[i][j]='2';
    //     //call for all 8-directions
    //     int dx[]={1,0,-1,0,1,1,-1,-1};
    //     int dy[]={0,-1,0,1,1,-1,1,-1};
    //     for(int k=0;k<8;k++){
    //         dfs(grid,i+dx[k],j+dy[k],n,m);
    //     }
    // }
    // // Function to find the number of islands.
    // int numIslands(vector<vector<char>>& grid) {
    //     // Code here
    //     int n=grid.size(),m=grid[0].size();
    //     int ans=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]=='1'){
    //                 dfs(grid,i,j,n,m);
    //                 ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    
    void bfs(vector<vector<char>>&grid,int i,int j,int n,int m,vector<vector<int>>&vis){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int>temp=q.front(); q.pop();
            int row=temp.first;
            int col=temp.second;
            for(int delRow=-1;delRow<=1;delRow++){
                for(int delCol=-1;delCol<=1;delCol++){
                    int nrow=row+delRow;
                    int ncol=col+delCol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1' ){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(grid,i,j,n,m,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends