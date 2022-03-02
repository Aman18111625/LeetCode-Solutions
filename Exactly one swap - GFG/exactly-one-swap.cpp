// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        // code here
        vector<int>freq(26 , 0);
        int len = S.length() ;
        long long res = 0 ;
        for(int i = 0 ; i < len ; i++){
            res  += i - freq[S[i] - 'a'];
            freq[S[i] - 'a']++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] >= 2){
                res++;
                break;
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends