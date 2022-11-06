// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    void helper(vector<vector<int>>&mat,int i,int j,int& n,string path,vector<string>&ans,
    vector<vector<int>>&vis){
        if(i<0 or j<0 or i>=n or j>=n or mat[i][j]==0) return ;//out of boundary or blocked
        if(vis[i][j]) return ;//already visited
        vis[i][j]=1;//mark visited
        //reach to destination
        if(i==n-1 && j==n-1){
            ans.push_back(path);
        }
        //call for all possible 4-directions
        helper(mat,i-1,j,n,path+"U",ans,vis);
        helper(mat,i+1,j,n,path+"D",ans,vis);
        helper(mat,i,j-1,n,path+"L",ans,vis);
        helper(mat,i,j+1,n,path+"R",ans,vis);
        vis[i][j]=0;//backtrack ->very important step
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==0 or m[n-1][n-1]==0) return ans;//source or destination is blocked
        helper(m,0,0,n,"",ans,vis);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends