// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    int LCS(string &a,string &b,int &n,int &m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0) dp[i][j]=0;
                else if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    public:
    int build_bridges(string str1, string str2)
    {
        // code here
        int n=str1.size(),m=str2.size();
        int ans=LCS(str1,str2,n,m);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends