// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
     bool dfs(int x, int y, vector<vector<int>>& v){
        int n=v.size();
        if(x<0 || x>=n || y<0 || y>=n || v[x][y]==0) return false;
        if(v[x][y]==2) return true;
        v[x][y] = 0;
        bool ans = dfs(x+1,y,v) || dfs(x-1,y,v) || dfs(x,y+1,v) || dfs(x,y-1,v);
        return ans;
     }
    bool is_Possible(vector<vector<int>>&v){
        int n = v.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    if(dfs(i,j,v)) return true;
                    else return false;
                }
            }
        }
    }
    //Approach-1 BFS
    //Function to find whether a path exists from the source to destination.
    // bool is_Possible(vector<vector<int>>& grid) 
    // {
    //     //code here
    //     int n=grid.size();
    //     queue<pair<int,int>>q;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(grid[i][j]==1) {
    //                 q.push({i,j});
    //                 grid[i][j]=0;
    //             }
    //         }
    //     }
    //     int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    //     while(!q.empty()){
    //         int x=q.front().first;
    //         int y=q.front().second;
    //          q.pop();
    //          for(int i=0;i<4;i++){
    //              int nx=x+dir[i][0];
    //              int ny=y+dir[i][1];
    //              if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]!=0){
    //                  if(grid[nx][ny]==2) return true;
    //                  q.push({nx,ny});
    //                  grid[nx][ny]=0;
    //              }
    //          }
    //     }
    //     return false;
    // }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends