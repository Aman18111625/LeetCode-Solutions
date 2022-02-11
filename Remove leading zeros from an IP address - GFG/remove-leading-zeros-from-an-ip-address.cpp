// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    string removeZeros(string& str)
    {
        int i=0,n=str.size();
        while(i<n && str[i]=='0') i++;
        return i==n?"0":str.substr(i);
    }
  public:
    string newIPAdd (string s)
    {
        //code here.
        int i=0,n=s.size();
        string ans="";
        while(i<n)
        {
            string temp="";
            while(i<n && s[i]!='.') temp+=s[i++];
            if(temp!="")
             {
                 ans+=removeZeros(temp);
                 if(i!=n) ans+=".";
             }
             i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends