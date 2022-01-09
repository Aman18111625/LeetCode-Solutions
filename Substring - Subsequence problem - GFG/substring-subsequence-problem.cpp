// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getLongestSubsequence(string A, string B) {
        // code here
        if(A==B) return A.length();
        int n=B.length(), m=A.length();
	    int max_len=0;
	    for(int i=0;i<n;i++)
	    { 
	        int low=0,high=i,curr=0;
	        while(low<m)
	        {
	            if(A[low]==B[high])
	            {
	                high++;
	                low++;
	                curr++;
	            }
	            else
	            {
	               low++; 
	            }
	        }
	        max_len=max(max_len,curr);
	    }
	    return max_len;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string A,B;

        cin >>A>>B;

        Solution ob;
        cout << ob.getLongestSubsequence(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends