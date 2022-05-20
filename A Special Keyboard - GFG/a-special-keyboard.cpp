// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string s1, string s2) {
        // code here
        int map[26]={0};
        for(int i=0;i<s1.size();i++){
            map[s1[i]-'a']=i;
        }
        int ans=0;
        int prev=0;
        for(int i=0;i<s2.size();i++){
            int id=map[s2[i]-'a'];
            ans+=abs(prev-id);
            prev=id;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends