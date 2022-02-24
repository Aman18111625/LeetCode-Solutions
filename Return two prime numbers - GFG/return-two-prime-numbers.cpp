// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<int>helper(vector<int>&primes,int n){
        vector<int>ans;
        for(int i=2;i<=n;i++){
            if(primes[i] && primes[n-i]){
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        }
        return ans;
    }
public:
    vector<int> primeDivision(int n){
        // code here
        vector<int>primes(n+1,true);
        primes[0]=primes[1]=false;
        for(int i=2;i<=n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=false;
                }
            }
        }
        return helper(primes,n);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends