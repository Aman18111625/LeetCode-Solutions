// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    
    bool dfs(vector<vector<int>>&grid,int n,int m,int srci,int srcj,int di,int dj){
        if(srci<0 or srci>=n or srcj<0 or srcj>=m ) return false;
        if(grid[srci][srcj]==0 or grid[srci][srcj]==INT_MAX) return false;
        if(srci==di && srcj==dj) return true;
        grid[srci][srcj]=INT_MAX;
        bool res=dfs(grid,n,m,srci+1,srcj,di,dj);
        res|=dfs(grid,n,m,srci-1,srcj,di,dj);
        res|=dfs(grid,n,m,srci,srcj+1,di,dj);
        res|=dfs(grid,n,m,srci,srcj-1,di,dj);
        return res;
    } 
    
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int srci,srcj,di,dj;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    srci=i;
                    srcj=j;
                }
                if(grid[i][j]==2){
                    di=i;
                    dj=j;
                }
            }
        }
        return dfs(grid,n,m,srci,srcj,di,dj);
    }
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