// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int i=0,j=0,res=INT_MAX,n=S.size();
        int freq[3]={0};
        while(j<n){
            freq[S[j]-'0']++;
            if(freq[0] && freq[1] && freq[2]){
                while(freq[0] && freq[1] && freq[2]){
                    freq[S[i]-'0']--;
                    i++;
                }
                res=min(res,j-(i-1)+1);
            }
            j++;
        }
        return res==INT_MAX?-1:res;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends