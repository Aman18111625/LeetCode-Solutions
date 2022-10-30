// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	bool isSafe(int i,int j,int n,int m,vector<vector<bool>> &vis){
        if(i >= 0 && i < n && j >=0 && j < m && !vis[i][j]) return true;
        return false;
    }
    
    vector<vector<int>> nearest(vector<vector<int>>grid){
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> res(n, vector<int>(m , 0));
	    vector<vector<bool>> vis(n , vector<bool>(m , false));
	   //to store pair of {i,j}
	    queue<pair<int,int>> q;
	    for(int i = 0;i < n;i++){
	        for(int j = 0;j < m;j++){
	            if(grid[i][j] == 1){
	                vis[i][j] = true;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    int delRow[]={-1,0,1,0};
	    int delCol[]={0,-1,0,1};
	    
	    while(!q.empty()){
	        pair<int,int>p = q.front();
	        q.pop();
	        int i=p.first,j=p.second;
	        for(int dir=0;dir<4;dir++){
	          int nrow =delRow[dir]+i;
	          int ncol =delCol[dir]+j;
	          if(isSafe(nrow,ncol,n,m,vis)){
	              vis[nrow][ncol]=true;
	              res[nrow][ncol]=1+res[i][j];
	              q.push({nrow,ncol});
	          }
	        }
	    }
	    return res;
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