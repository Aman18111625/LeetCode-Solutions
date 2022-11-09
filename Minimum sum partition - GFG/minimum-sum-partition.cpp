//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int N)  { 
	    // Your code goes 
	    int sum=0;
	    for(int i=0;i<N;i++) sum+=arr[i];
	    int dp[N+1][sum+1];
	    for(int i=0;i<N+1;i++)
	    {
	        for(int j=0;j<sum+1;j++)
	         {
	             if(i==0) dp[i][j]=false;
	             if(j==0) dp[i][j]=true;
	         }
	    }
	    for(int i=1;i<N+1;i++)
	    {
	        for(int j=1;j<sum+1;j++)
	        {
	            if(arr[i-1]<=j)
	                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            else
	               dp[i][j]=dp[i-1][j];
	        }
	    }
	    //we need only last line of dp and sum till half
	    int j;
	      for(j=sum/2;j>=0;j--)
            {
                if(dp[N][j]==true)
                {
                    break;
                }
            }
            int answer=sum-(2*j);
            return answer;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends