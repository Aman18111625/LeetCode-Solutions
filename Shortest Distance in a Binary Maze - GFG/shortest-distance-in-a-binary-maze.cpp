//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isSafe(vector<vector<int>>&grid,vector<vector<bool>>&vis,int n,int m,int i,int j){
        return i>=0 && i<n && j>=0 && j<m && vis[i][j]==false && grid[i][j]==1;
    }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest) {
        // code here
        //edge case
        if(grid[src.first][src.second]==0 || grid[dest.first][dest.second]==0) 
           return -1;
        int n=grid.size(),m=grid[0].size();
        //to keep track of visited or not
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,pair<int,int>>>q;//key->dist,value->{i,j}
        vis[src.first][src.second]=true;
        q.push({0,src});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int dist=temp.first;
            pair<int,int>d=temp.second;
            if(d==dest){
                return dist;
            }
            int rowNum[] = {-1, 0, 0, 1};
            int colNum[] = {0, -1, 1, 0};
            for(int i=0;i<4;i++){
                int x=d.first+rowNum[i];
                int y=d.second+colNum[i];
                if(isSafe(grid,vis,n,m,x,y)){
                  q.push({dist+1,{x,y}});
                  vis[x][y]=true;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends