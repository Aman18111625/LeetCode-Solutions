// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{ 
    bool isValid(int x,int y,int rows,int cols){
        if(x<0 or x>=rows or y<0 or y>=cols) return false;
        return true;
    }
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<int,int>>q;
	    vector<vector<int>>vis(n,vector<int>(m,false));
	    vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                vis[i][j]=true;
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	         q.pop();
	         int dist=ans[x][y];
	         for(int i=0;i<4;i++){
	             int new_x=x+dir[i].first;
	             int new_y=y+dir[i].second;
	             if(isValid(new_x,new_y,n,m) && !vis[new_x][new_y]){
	                 vis[new_x][new_y]=true;
	                 q.push({new_x,new_y});
	                 ans[new_x][new_y]=1+dist;
	             } 
	         }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends