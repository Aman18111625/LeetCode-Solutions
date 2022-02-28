// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int i=0,j=-1,res=INT_MAX,n=S.size();
        int freq[3]={0};
        while(i<n){
            while((!freq[0] or !freq[1] or !freq[2]) && j+1<n){
                freq[S[j+1]-'0']++;
                j++;
            }
            if(freq[0] && freq[1] && freq[2])  res=min(res,j-i+1);
                if(j>=i){
                    freq[S[i]-'0']--;
                    i++;
                }else{
                    freq[S[i]-'0']--;
                    i++;
                    j=i-1;
                }
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