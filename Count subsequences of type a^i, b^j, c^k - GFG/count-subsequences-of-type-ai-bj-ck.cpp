// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        int mod=1000000007;
        int a=0,ab=0,abc=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='a')
             a=((2*a%mod)%mod+1)%mod;
            else if(ch=='b')
             ab=((2*ab%mod)%mod+(a%mod))%mod;
            else if(ch=='c')
            abc=((2*abc%mod)%mod+(ab%mod))%mod;
        }
        return abc%mod;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends