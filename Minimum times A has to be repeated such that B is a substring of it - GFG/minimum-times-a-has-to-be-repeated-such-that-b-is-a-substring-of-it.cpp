// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
       int k=1;
       string s=A;
       while(s.size()<B.size())
       {
           s+=A;
           k++;
       }
       
       int idx=s.find(B);
       if(idx!=-1) return k;
       s+=A;
       k++;
       idx=s.find(B);
       if(idx!=-1) return k;
       return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends