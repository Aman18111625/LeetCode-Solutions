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
	    int max_len=0,c;
	    for(int i=0;i<n;i++)
	    { 
	        int k=i,j=0;
	         c=0;
	        while(j<m)
	        {
	            if(A[j]==B[k])
	            {
	                k++;
	                j++;
	                c++;
	            }
	            else
	            {
	               j++; 
	            }
	        }
	        max_len=max(max_len,c);
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