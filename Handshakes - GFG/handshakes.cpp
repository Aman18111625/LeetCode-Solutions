// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
  /* Recursive Solution
        if(N%2) return 0;//even number
        if(N==0) return 1;//base case
        int res=0;
        for(int i=0;i<N;i+=2)
        {
            res+=(count(i)*count(N-i-2));
        }
        return res;*/
    int count(int N){
        // code here
        int dp[N+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;//base case
        for(int i=2;i<=N;i+=2)
        {
            for(int j=2;j<=i;j+=2)
            {
                  dp[i]+=(dp[i-j]*dp[j-2]);
            }
        }
        return dp[N];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends