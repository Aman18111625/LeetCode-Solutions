// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<long long> distributeCandies(int N, int K) {
        // code here
        vector<long long >ans(K,0);
        long long cnt=0;
        while(N){
            for(int i=0;i<K && N>0 ;i++){
                if(N>K*cnt+i+1){
                    ans[i]+=(K*cnt+i+1);
                    N-=(K*cnt+i+1);
                }else{
                    ans[i]+=N;
                    return ans;
                }
            }
            cnt++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends