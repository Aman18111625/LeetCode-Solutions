// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    int helper(int i,int j,vector<vector<int>>&mat,int xd,int yd){
        if(i==xd && j==yd) return 0;
        if(i<0 or i>=mat.size() or j<0 or j>=mat[0].size()) return -1e9;
        if(mat[i][j]!=1) return -1e9;
        mat[i][j]=0;
        int right=1+helper(i,j+1,mat,xd,yd);
        int left=1+helper(i,j-1,mat,xd,yd);
        int up=1+helper(i-1,j,mat,xd,yd);
        int down=1+helper(i+1,j,mat,xd,yd);
        mat[i][j]=1;
        return (int)max({left,right,up,down});
    }
public:
    int longestPath(vector<vector<int>> mat, int xs, int ys, int xd, int yd)
    {
        // code here
        if(mat[xd][yd]==0 || mat[xs][ys]==0) return -1;
        return helper(xs,ys,mat,xd,yd);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends