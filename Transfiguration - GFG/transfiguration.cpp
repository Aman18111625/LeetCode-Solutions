// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	if(A.size()!=B.size()) return -1;
    	int sum=0;
    	for(auto &ch : A) sum+=ch;
    	for(auto &ch : B) sum-=ch;
    	if(sum!=0) return -1;
    	int n=A.size(),i=n-1,j=n-1,cnt=0;
    	while(i>=0 && j>=0)
    	{
    	    if(A[i]==B[j]) i--,j--;
    	    else {
    	        cnt++,i--;
    	    }
    	}
    	return cnt;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends