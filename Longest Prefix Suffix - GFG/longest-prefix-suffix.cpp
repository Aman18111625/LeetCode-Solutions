// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n=s.size();
	    vector<int>LPS(n);
	    int i=1,j=0;
	    LPS[0]=0;
	    while(i<n){
	        if(s[i]==s[j]){
	            j++;
	            LPS[i]=j;
	            i++;
	        }
	        else{
	            if(j){
	                j=LPS[j-1];
	            }else{
	                LPS[i]=0;
	                i++;
	            }
	        }
	    }
	    return LPS[n-1];
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends