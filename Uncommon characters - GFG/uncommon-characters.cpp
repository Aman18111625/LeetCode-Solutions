//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            vector<int>freq1(26,0),freq2(26,0);
            for(auto ch: A){
                freq1[ch-'a']++;
            }
            for(auto ch: B){
                freq2[ch-'a']++;
            }
            
            string ans="";
            for(int i=0;i<26;i++){
             if((freq1[i]==0 && freq2[i]!=0) || (freq1[i]!=0 && freq2[i]==0))
               ans+=(i+'a');
            }
            return ans.empty()?"-1":ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends