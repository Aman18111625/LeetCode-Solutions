// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int fresh=0;
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        int dir[5]={-1,0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            bool flag=false;
            while(size--){
               int x=q.front().first;
               int y=q.front().second;
               q.pop();
               //traverse all the adjacent in all four direction
               for(int d=0;d<4;d++){
                   int new_x=x+dir[d];
                   int new_y=y+dir[d+1];
                   if(new_x>=0 && new_x<n &&new_y>=0 && new_y<m && grid[new_x][new_y]==1){
                     q.push({new_x,new_y});
                     grid[new_x][new_y]=2;
                     flag=true;
                     fresh--;
                   }
               }
            }
           if(flag) {
               ans++;
           }
        }
        if(fresh>0) return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends