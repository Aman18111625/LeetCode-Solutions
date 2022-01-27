// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    char prev='0';
    int cnt0=0,cnt1=0,n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]!=prev)
          cnt0++;
        if(prev=='0') prev='1';
        else prev='0';
    }
    prev='1';
    for(int i=0;i<n;i++)
    {
        if(s[i]!=prev) cnt1++;
        if(prev=='1') prev='0';
        else prev='1';
    }
    return min(cnt0,cnt1);
}