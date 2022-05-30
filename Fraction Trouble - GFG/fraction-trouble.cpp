// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
        int num=0,deno=1;
        for(int q=10000;q>=2;q--){
            int p=(n*q-1)/d;
            if(p*deno>=q*num){
                deno=q;
                num=p;
            }
        }
        int g=__gcd(num,deno);
        vector<int>ans;
        ans.push_back(num/g);
        ans.push_back(deno/g);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends