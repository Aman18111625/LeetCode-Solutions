//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    long long mod=1e9+7;
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        if(n==0 or n==1) return 1;
        long long prev2=2,prev1=1,prev0=1;
        for(int i=3;i<=n;i++){
            long long curr = (prev2+prev1+prev0)%mod;
            prev0=prev1;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends